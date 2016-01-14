colormake
if [ $? -eq 0 ]
then
    echo "Compilation Successful"
else
    echo "Compilation Failed"
    exit 1
fi

colormake install
/etc/init.d/openvswitch-switch stop
/etc/init.d/openvswitch-controller stop
update-rc.d openvswitch-controller disable
/etc/init.d/openvswitch-switch start
