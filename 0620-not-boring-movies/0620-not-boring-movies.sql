# Write your MySQL query statement below
SELECT id, movie, description, rating
From Cinema
where id % 2 = 1 AND description != 'boring'
Order by rating DESC;