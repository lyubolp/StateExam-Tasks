Use movies

--Task 1--
SELECT ME.NAME, M.YEAR, COUNT(*) AS CNT
FROM MOVIEEXEC ME
JOIN MOVIE M
ON ME.CERT# = M.PRODUCERC#
GROUP BY ME.CERT#, ME.NAME, M.YEAR;


--Task 2--
Select m.NAME
FROM MOVIESTAR m 
JOIN (Select MAX(BIRTHDATE) as BD FROM MOVIESTAR) as m3
ON m.BIRTHDATE = m3.BD


