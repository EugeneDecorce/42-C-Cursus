CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER IF NOT EXISTS 'edecorce'@'%' IDENTIFIED BY 'edecorce';
GRANT ALL PRIVILEGES ON wordpress.* TO 'edecorce'@'%';
FLUSH PRIVILEGES;
ALTER USER 'edecorce'@'localhost' IDENTIFIED BY 'edecorce';