-- Create the WordPress database if it doesn't exist
CREATE DATABASE IF NOT EXISTS wordpress;

-- Create the 'edecorce' user with a secure password if it doesn't exist
CREATE USER IF NOT EXISTS 'edecorce'@'%' IDENTIFIED BY '12345';

-- Grant all privileges on the WordPress database to the 'edecorce' user
GRANT ALL PRIVILEGES ON wordpress.* TO 'edecorce'@'%';

-- Apply the changes to the privileges
FLUSH PRIVILEGES;

-- Securely alter the 'root' user password for localhost
ALTER USER 'root'@'localhost' IDENTIFIED BY 'root12345';