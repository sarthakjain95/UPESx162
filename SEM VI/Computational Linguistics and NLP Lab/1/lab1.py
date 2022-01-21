import pandas as pd

# 1) Read it as a .csv file and create a dataframe and display it.
df = pd.read_csv(
    "train_triplets_sample.txt", 
    sep="\t",
    names=["user", "song", "play_count"])
print(df)

# 2) Display per unique user play_count.
user_play_count = df.groupby("user")["play_count"].sum()
# Convert from series to dataframe
user_play_count = pd.DataFrame({
    "user": user_play_count.index, 
    "play_count": user_play_count.values}) 
print(user_play_count)

# 3) Display per unique song play_count.
song_play_count = df.groupby("song")["play_count"].sum()
song_play_count = pd.DataFrame({
    "song": song_play_count.index, 
    "play_count": song_play_count.values})
print(song_play_count)

# 4) Display top users and songs with respect to play_count and save as different .csv files.
top_users = user_play_count.sort_values("play_count", ascending=False)
top_songs = song_play_count.sort_values("play_count", ascending=False)
# Display
print(top_users)
print(top_songs)
# Save
top_users.to_csv("top_users.csv")
top_songs.to_csv("top_songs.csv")

