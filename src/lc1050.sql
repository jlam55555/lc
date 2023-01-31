# Write your MySQL query statement below

SELECT actor_id, director_id FROM
(SELECT COUNT(*) AS count, actor_id, director_id
FROM ActorDirector
GROUP BY actor_id, director_id) AS p
WHERE count >= 3
