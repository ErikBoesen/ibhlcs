import tweepy
import json
import os

with open(os.getenv("HOME") + "/twitter_keys.json") as f:
    config = json.load(f)

auth = tweepy.OAuthHandler(config["consumer_key"],
                           config["consumer_secret"])
auth.set_access_token(config["access_token"],
                      config["access_token_secret"])

# Construct the API instance
api = tweepy.API(auth)

for user in tweepy.Cursor(api.friends).items():
    print(user.profile_link_color)
