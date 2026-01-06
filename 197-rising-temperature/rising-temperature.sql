-- we can join with self
SELECT 
    w2.id
FROM Weather AS w1
INNER JOIN Weather AS w2  -- just matches
    ON DATEDIFF(w1.recordDate,w2.recordDate)=-1
WHERE W1.temperature < w2.temperature