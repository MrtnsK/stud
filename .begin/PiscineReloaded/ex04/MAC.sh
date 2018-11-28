ifconfig | grep ether | sed "s/ether //g" | cut -c2- | rev | cut -c2- | rev
