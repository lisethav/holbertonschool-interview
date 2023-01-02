#!/usr/bin/python3
"""
Count parse hot topics Reddit Api
"""


import requests


def count_words(subreddit, word_list):
    """ count words
    """
    base_url = 'https://www.reddit.com'
    payload = {'q': word_list[0], 'sort': 'relevance'}
    response = requests.get(
        base_url + '/r/' + subreddit + '/hot.json',
        headers={'User-Agent': 'Custom user'},
        params=payload
    )

    """print(response.status_code)
    print(response.text)
"""
    values = response.json()
    count = 0

    for i in range(len(values['data']['children'])):
        count += 1

    word_count = {x: count for x in word_list}
    for key, value in word_count.items():
        print("{} : {}".format(key, value))

    return word_count