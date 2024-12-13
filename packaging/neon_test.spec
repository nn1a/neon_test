Name:           neon_test
URL:            https://www.tizen.org/
Summary:        gcc neon test
License:        MIT
Group:          Testing
Version:        1.0.0
Release:        0
Source0:        %{name}-%{version}.tar.gz

%description
armv7l neon test

%prep
%setup -q

%build

set +x

for opt in O3 O2 O1; do

gcc ${LDFLAGS} ${CFLAGS} -${opt} neon_test.c -o ${opt}_neon_test

echo ""
echo "Opt level ${opt}"
echo "[Start search :64]"
objdump -d ${opt}_neon_test | grep ":64" || echo "Not Found"
echo "[Done search :64]"

echo "RUN ${opt}_neon_test"
./${opt}_neon_test || echo "FAIL"
done

echo ""

%install
install -d %{buildroot}%{_bindir}/
install -m 755 O?_neon_test %{buildroot}%{_bindir}/

%files
%{_bindir}/*_neon_test

