# Write your MySQL query statement below
SELECT p.product_id, IF(SUM(u.units) IS NOT NULL, ROUND(SUM(p.price * u.units) / SUM(u.units), 2), 0) AS average_price 
From Prices p LEFT JOIN UnitsSold u
ON p.product_id = u.product_id 
AND p.start_date <= u.purchase_date AND p.end_date >= u.purchase_date
Group BY p.product_id;
# SELECT Prices.product_id, IF(SUM(UnitsSold.units) IS NOT NULL, ROUND(SUM(UnitsSold.units * Prices.price) / SUM(UnitsSold.units), 2), 0) AS average_price
# FROM Prices LEFT JOIN UnitsSold
# ON Prices.product_id = UnitsSold.product_id AND 
# UnitsSold.purchase_date BETWEEN Prices.start_date AND Prices.end_date
# GROUP BY Prices.product_id