# Write your MySQL query statement below
SELECT product_id,'store1' as store , store1 as price FROM Products where store1 is NOT NULL
UNION
SELECT product_id,'store2' as store , store2 as price FROM Products where store2 is NOT NULL
UNION
SELECT product_id,'store3' as store , store3 as price FROM Products where store3 is NOT NULL ORDER BY 1 ASC;