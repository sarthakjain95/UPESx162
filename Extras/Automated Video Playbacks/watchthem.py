
#! /usr/bin/env python3

import getpass,time

from selenium.webdriver import Firefox
from selenium.webdriver.firefox.options import Options

from bs4 import BeautifulSoup


import re

# Install and configure geckodriver for linux

# Set up geckodriver for linux
# wget https://github.com/mozilla/geckodriver/releases/download/v0.19.1/geckodriver-v0.19.1-linux64.tar.gz
# tar -xvfz geckodriver*
# chmod +x geckodriver*
# sudo su
# mv geckodriver* /usr/local/bin

# Install selenium
# pip3 install selenium

# Install beautifulsoup4
# pip3 install beautifulsoup4


#-----------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------

last_line_length= 0

def eraseLastLine():
	global last_line_length
	print("\r"+" "*last_line_length+"\r", end="")

def updateText(data):
	global last_line_length
	eraseLastLine()
	print(data, end="")
	last_line_length= len(data)

def updateProgressBar(s_i=1, v_i=0, t_v=0, st=0, l=0):
	global last_line_length
	if st==0:
		eraseLastLine()
		last_line_length= len( "Session {0}".format(s_i) )
		print("Session {0}".format(s_i), end="")
	else:
		eraseLastLine()
		cur= int( (st/l)*10 )
		per= round(st/l*100, 2)
		st= round(st,1)
		prog= "Session {0} ({1}/{2}) : {3}% [{4}{5}] ({6}/{7})".format(s_i, v_i, t_v, per, "="*(cur)+">", "-"*(10-cur-1), st, l )
		last_line_length= len(prog)
		print("\r"+ prog, end="")

#-----------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------

print("\nSetting up Firefox as headless-browser ...")

opts= Options()
opts.set_headless()
assert opts.headless  # Operating in headless mode
browser= Firefox(options=opts)

base_url= "https://learn.upes.ac.in"

current_course_link= ""


print("\nFetching Login Page for UPES Blackboard ...")
browser.get(base_url+"/webapps/login/")
print("Got the Login Page.")

soup= BeautifulSoup(browser.page_source, features="html.parser")

while soup.title.string == "Learn @ UPES":

	print("\nYou are currently not Logged-In.")
	
	print("\nIf you feel like you have no reason to trust this")
	print("program with your password, I encourage you to go")
	print("ahead and check the source code.")
	
	print("\nEnter your login details for UPES Blackboard.\n")

	username= input("Enter your User Name: ")
	password= getpass.getpass("Enter your Password: ")

	print("\nTrying to Log-In to the website ...")
	
	browser.find_element_by_id("user_id").send_keys(username)
	browser.find_element_by_id ("password").send_keys(password)

	browser.find_element_by_id("entry-login").click()

	soup= BeautifulSoup(browser.page_source, features="html.parser")
	# print(BeautifulSoup(browser.page_source, features="html.parser").title.string)
	if soup.title.string == "Learn @ UPES":
		print("Error Occured. Try Again.")

	print("Login was Successful!")

	#============================================================================
	print("Agreeing to cookies policy.")
	browser.find_element_by_id("agree_button").click()
	#============================================================================

print("\nWaiting for all content to load ...")
time.sleep(5)

soup= BeautifulSoup(browser.page_source, features="html.parser")
print("Your are now on page titled: {0}".format(soup.title.string))

if soup.title.string != "My Institution – Blackboard Learn":
	print("Error Occured you are not on the \'My Courses\' page.")
	exit(0)

print("\nFetching the names of all courses ...")

courses = []
# print( soup.find('div',{"id":"column1"}) )
for li in soup.find('div',{"id":"column1"}).find_all('li'):
	a_tag= li.find('a',{"target":"_top"})
	if a_tag:
		courses.append( [ a_tag.text, a_tag['href'] ] )


print("Your courses are:\n")
for c in courses:
	print(courses.index(c)+1,c[0])


while True:
	try:
		choice= input("\nEnter your choice:")
		choice= int(choice)-1
		if choice<0 or choice>=len(courses):
			raise "Invalid Choice"
		break
	except:
		print("Invalid choice. Retry.")

print("\nCourse selected: {0} ".format(courses[choice][0]))
# print(courses[choice])


print("Redirecting to the course webpage")

current_course_link= base_url + (courses[choice][1]).strip()

browser.get( current_course_link )
time.sleep(5)

soup= BeautifulSoup(browser.page_source, features="html.parser")
print("Your are now on page titled: {0}".format(soup.title.string))

print("\nFinding links for videos")

course_content= soup.find('ul',{"id":"courseMenuPalette_contents"}).find_all('li')
videos_links= []

f2f_regex= re.compile(r'''[A-Z].*?(\(F2F\)).*?''')

for entry in course_content:
	a_tag= entry.find('a')
	if a_tag and f2f_regex.findall(a_tag.text):
		videos_links.append( a_tag )

if len(videos_links) == 0:
	print("No videos found for this course!")
	#-----------------------------------------------------------------------------------
	exit()
	#-----------------------------------------------------------------------------------
else:
	print("\nHere's a list of online videos for this course:\n")
	for tag in videos_links:
		print( tag.text )


print("\nStarting Video playback sessions.")

for f2f in videos_links:

	print()

	session_index= videos_links.index(f2f) + 1
	updateProgressBar(session_index)

	updateText("Fetching Session Page ...")
	browser.get( base_url+f2f['href'] )
	time.sleep(3)
	updateText("Got Session page ...")

	soup= BeautifulSoup(browser.page_source, features="html.parser")

	content= soup.find("ul", {"id":"content_listContainer"}).find_all('li')
	vids= []

	session_name= soup.find("span", {"id":"pageTitleText"}).find("span").text
	updateText( "Now on " + session_name[0:session_name.index(":")] )

	time.sleep(0.5)
	# Iterate on content to see if the video is to be played
	# Get information like number of videos on the page and gather ids and objects for all
	for item in content:
		# updateText("Computing if link in item!")
		item= item.find("div", {"class":"details"})
		if item.find("div", {"class":"vtbegenerated"}):
			item= item.find("div", {"class":"vtbegenerated"})
			if item.find('a'):
				item= item.find('a')
				# print(item)
				vids.append( ["embed",item] )
			elif item.find('iframe'):
				item= item.find('iframe')
				# print(item)
				vids.append( ["iframe",item] )
		# time.sleep(3)
	updateText("{0} Playable Video(s) found".format( len(vids) ))

	for video in vids:

		video_i= vids.index(video)
		updateText("Playing video ...")
		
		if video[0] == "embed":
			updateText("Clicked on the video")
			browser.find_element_by_xpath("//*[@title=\""+video[1]['title']+"\"]").click()
			updateText("Waiting to load ...")
			time.sleep(2)
			# vid= browser.find_elements_by_class_name("lb-wrapper")
			vid_soup= BeautifulSoup(browser.page_source, features="html.parser")
			vid_soup= vid_soup.find("div", {"class":"previewDiv ytIframeClass"})
			# print(vid_soup)
			browser.find_element_by_id( vid_soup['id'] ).click()
			time.sleep(2)
			browser.switch_to.frame( vid_soup.find("iframe")['id'] )
			updateText("Clicked on the play button")
			time.sleep(1)
			iframe_soup= BeautifulSoup(browser.page_source, features="html.parser")
			duration= iframe_soup.find("span", {"class":"ytp-time-duration"}).text
			total_time= int(duration.split(":")[0])*60 + int(duration.split(":")[1])
			duration= 0

			while duration < total_time:
				duration+=1
				time.sleep(1)
				updateProgressBar(session_index, video_i, len(vids), duration, total_time)

			browser.switch_to.default_content()
			browser.find_elements_by_class_name("lbAction u_floatThis-right").click()

		else:
			
			browser.find_element_by_id(video[1]['id']).click()

			# changing browser content
			browser.switch_to.frame( browser.find_element_by_id( video[1]['id'] ) )
			iframe_soup= BeautifulSoup(browser.page_source, features="html.parser")
			
			duration= iframe_soup.find("span", {"class":"ytp-time-duration"}).text
			updateText("Total Duration :"+duration)
			# time.sleep(120)
			total_time= int(duration.split(":")[0])*60 + int(duration.split(":")[1])
			duration= 0
			# def updateProgressBar(s_i=1, v_i=0, t_v=0, st=0, l=0)
			while duration < total_time:
				duration+=1
				time.sleep(1)
				updateProgressBar(session_index, video_i, len(vids), duration, total_time)

			browser.switch_to.default_content()
			print()
		


# print("Closing the browser session.")
print()
browser.quit()
print("Closed the browser session.")
