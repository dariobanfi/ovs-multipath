colormake
if [ $? -eq 0 ]
then
    echo "Compilation Successful"
else
    echo "Compilation Failed"
    exit 1
fi

colormake install
colormake modules_install
rmmod openvswitch
depmod -a
/etc/init.d/openvswitch-switch stop
/etc/init.d/openvswitch-controller stop
update-rc.d openvswitch-controller disable
/etc/init.d/openvswitch-switch start