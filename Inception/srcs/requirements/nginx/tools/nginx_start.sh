#!/bin/bash

# Define SSL certificate and key paths
CERT_FILE="/etc/ssl/certs/nginx.crt"
KEY_FILE="/etc/ssl/private/nginx.key"

# Check if the SSL certificate file doesn't exist
if [ ! -f "$CERT_FILE" ]; then
	echo "Nginx: Setting up SSL..."

	# Generate the SSL certificate and key
	openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
		-keyout "$KEY_FILE" \
		-out "$CERT_FILE" \
		-subj "/C=TR/ST=KOCAELI/L=GEBZE/O=42Kocaeli/CN=buyildir.42.fr"

	# Check if the SSL setup was successful
	if [ $? -eq 0 ]; then
		echo "Nginx: SSL is set up successfully!"
	else
		echo "Nginx: Failed to set up SSL." >&2
		exit 1
	fi
else
	echo "Nginx: SSL is already set up."
fi

# Execute the command passed as arguments to the script
exec "$@"
