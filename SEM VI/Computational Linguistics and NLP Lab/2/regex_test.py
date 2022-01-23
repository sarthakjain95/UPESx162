
'''
Explore the (regular expressions) library in detail. 
What kind of analysis you can in it. Explain with proper codes. 
'''

import re

raw_data = ''' 
Lorem ipsum dolor sit amet, consectetur adipiscing 9101001020 elit, sed do eiusmod tempor ergjero@gmail.com incididunt ut labore et dolore magna aliqua. Ut enim ad minim 91-4234235423 veniam, quis nostrud exercitation https://google.com ullamco laboris nisi ut aliquip ex ea https://stackoverflow.com/questions/tagged/ commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat foo@gmail.com nulla pariatur. Excepteur sint occaecat cupidatat non proident, +91 1500110110 sunt in culpa qui officia deserunt mollit anim id est https://www.stefanjudis.com/today-i-learned/non-capturing-groups-in-regular-expressions/ laborum.
'''

"""
'[a-zA-Z0-9]' basically matches any character from the given list
'+' matches the previous token between one and unlimited times, as many times as possible
'\@gmail\.com' matches the same string
Combined together, this pattern matches all valid gmail addresses
This is a very basic regex, so it cannot match emails like sarthak.jain@gmail.com
But it can be modified to match more complex emails.
"""

# A basic regex to match Gmail addresses
gmail_regex = re.compile(r'''[a-zA-Z0-9]+\@gmail\.com''')
print(gmail_regex.findall(raw_data))

"""
'\+?' This basically matches and '+' in front of phone numbers and '?' makes it optional
'(\d{1,3})?' This matches the country code in front of phone numbers \d means a digit and {1,3} means 1 to 3 digits
'(?:\-|\ )?' This matches the character between country-code and phone number. This character can be a \- or a space. '?:' makes this a non-capturing group, meaning this will be matches, but will not be included in the result
(\d{10}) This just matches a group of 10 digits
"""

# A regex to gather all phone numbers
phone_number_regex = re.compile(r'''\+?(\d{1,3})?(?:\-|\ )?(\d{10})''')
print(phone_number_regex.findall(raw_data))

"""
'(https?:\/\/)' This matches the protocol of the url (http or https). '?' in front of 's' makes it optional.
'(www\.)?' This matches 'www.' in front of urls. This is also optional
'(\S*)' '\s' basically matches all whitespace characters. Uppercase '\S' matches all the characters that are not whitespaces, so we have capturing all the characters after protocol, until a whitespace is encountered, because we know urls do not contain whitespaces. 
This is again a very basic regex but it can be modified to match more complex cases.
"""

# Regex to gather urls
url_regex = re.compile(r'''(https?:\/\/)(www\.)?(\S+)''')
print(url_regex.findall(raw_data))
