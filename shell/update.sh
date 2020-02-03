#!/bin/bash

# Update the Raspberry Pi

echo GRABBING UPDATES FROM ONLINE
sudo apt-get update
sudo apt update

echo UPDATING THE RASPBERRY PI
sudo apt-get upgrade -y
sudo apt-get dist-Upgrade -y
sudo apt full-upgrade -y
sudo rpi-update -y

echo REMOVING UNEEDED UPDATES
sudo apt autoremove -y

read -p "Press [Enter] key to start reboot..."
sudo reboot
