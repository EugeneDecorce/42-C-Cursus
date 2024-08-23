#!/bin/bash

# Update the PHP-FPM socket configuration to use a TCP socket on port 9000
sed -i "s|listen = /run/php/php7.3-fpm.sock|listen = 9000|" "/etc/php/7.3/fpm/pool.d/www.conf"

# Set appropriate ownership and permissions for the web directory
chown -R www-data:www-data /var/www/*
chmod -R 755 /var/www/*

# Ensure the PHP run directory exists and create the PID file
mkdir -p /run/php/
touch /run/php/php7.3-fpm.pid

# Check if WordPress is not already set up by looking for the wp-config.php file
if [ ! -f /var/www/html/wp-config.php ]; then
	echo "WordPress: setting up..."
	
	# Create the WordPress directory if it doesn't exist
	mkdir -p /var/www/html
	
	# Download and set up WP-CLI
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp
	
	# Download WordPress core files
	cd /var/www/html
	wp core download --allow-root
	
	# Move the wp-config.php file into the correct directory
	mv /var/www/wp-config.php /var/www/html/
	
	echo "WordPress: creating users..."
	
	# Install WordPress with the provided environment variables
	wp core install --allow-root --url="${WP_URL}" --title="${WP_TITLE}" \
	--admin_user="${WP_ADMIN_LOGIN}" --admin_password="${WP_ADMIN_PASSWORD}" --admin_email="${WP_ADMIN_EMAIL}"
	
	# Create a new user
	wp user create --allow-root "${WP_USER_LOGIN}" "${WP_USER_EMAIL}" --user_pass="${WP_USER_PASSWORD}"
	
	echo "WordPress: set up!"
fi

# Execute the command passed as arguments to the script
exec "$@"
