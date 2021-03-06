# Start of section pegasus/rpm/tog-specfiles/tog-pegasus-build.spec
#
export PEGASUS_ROOT=%PEGASUS_RPM_ROOT
export PEGASUS_HOME=%PEGASUS_RPM_HOME
export PEGASUS_PLATFORM=%PEGASUS_HARDWARE_PLATFORM
export PEGASUS_ARCH_LIB=%PEGASUS_ARCH_LIB
export PEGASUS_ENVVAR_FILE=$PEGASUS_ROOT/env_var_Linux.status

export OPENSSL_HOME=%OPENSSL_HOME
export OPENSSL_BIN=%OPENSSL_BIN
export LD_LIBRARY_PATH=$PEGASUS_HOME/lib
export PATH=$PEGASUS_HOME/bin:$PATH

export PEGASUS_EXTRA_C_FLAGS="$RPM_OPT_FLAGS -g -Wno-unused"
export PEGASUS_EXTRA_CXX_FLAGS="$PEGASUS_EXTRA_C_FLAGS"
export PEGASUS_EXTRA_LINK_FLAGS="$RPM_OPT_FLAGS"
#export PEGASUS_EXTRA_LINK_FLAGS="$RPM_OPT_FLAGS -g -pie -Wl,-z,relro,-z,now,-z,nodlopen,-z,noexecstack"

%if %{PEGASUS_BUILD_TEST_RPM}
export PEGASUS_TMP=/usr/share/Pegasus/test/tmp
export PEGASUS_DISPLAYCONSUMER_DIR="$PEGASUS_TMP"
%endif

%if %{JMPI_PROVIDER_REQUESTED}
sed -i 's/PEGASUS_ENABLE_JMPI_PROVIDER_MANAGER=.*$/PEGASUS_ENABLE_JMPI_PROVIDER_MANAGER=true/' $PEGASUS_ENVVAR_FILE
%else
sed -i 's/PEGASUS_ENABLE_JMPI_PROVIDER_MANAGER=.*$/PEGASUS_ENABLE_JMPI_PROVIDER_MANAGER=false/' $PEGASUS_ENVVAR_FILE
%endif

make -f $PEGASUS_ROOT/Makefile.Release create_ProductVersionFile
make -f $PEGASUS_ROOT/Makefile.Release create_CommonProductDirectoriesInclude
make -f $PEGASUS_ROOT/Makefile.Release create_ConfigProductDirectoriesInclude
make %{?_smp_mflags} -f $PEGASUS_ROOT/Makefile.Release all
chmod 777 %PEGASUS_RPM_HOME
make -f $PEGASUS_ROOT/Makefile.Release repository
#
# End of section pegasus/rpm/tog-specfiles/tog-pegasus-build.spec
