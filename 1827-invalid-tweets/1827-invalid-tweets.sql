# Write your MySQL query statement below
select tweet_id
from Tweets
Where CHAR_LENGTH(content) > 15;