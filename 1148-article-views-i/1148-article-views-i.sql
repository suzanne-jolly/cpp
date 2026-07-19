SELECT DISTINCT viewer_id as id
FROM views
WHERE author_id = viewer_id
order by author_id