make
make install
make modules_install
rmmod openvswitch
depmod -a
/etc/init.d/openvswitch-switch stop
/etc/init.d/openvswitch-controller stop
update-rc.d openvswitch-controller disable
/etc/init.d/openvswitch-switch start