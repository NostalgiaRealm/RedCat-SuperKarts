; 004a17c0 FUN_004a17c0
004a17c0	8b44240c	MOV EAX,dword ptr [ESP + 0xc]
004a17c4	8b4c2408	MOV ECX,dword ptr [ESP + 0x8]
004a17c8	8b542404	MOV EDX,dword ptr [ESP + 0x4]
004a17cc	d94020	FLD float ptr [EAX + 0x20]
004a17cf	d84908	FMUL float ptr [ECX + 0x8]
004a17d2	d94104	FLD float ptr [ECX + 0x4]
004a17d5	d84810	FMUL float ptr [EAX + 0x10]
004a17d8	dec1	FADDP
004a17da	d901	FLD float ptr [ECX]
004a17dc	d808	FMUL float ptr [EAX]
004a17de	dec1	FADDP
004a17e0	d9410c	FLD float ptr [ECX + 0xc]
004a17e3	d84830	FMUL float ptr [EAX + 0x30]
004a17e6	dec1	FADDP
004a17e8	d91a	FSTP float ptr [EDX]
004a17ea	d94024	FLD float ptr [EAX + 0x24]
004a17ed	d84908	FMUL float ptr [ECX + 0x8]
004a17f0	d94104	FLD float ptr [ECX + 0x4]
004a17f3	d84814	FMUL float ptr [EAX + 0x14]
004a17f6	dec1	FADDP
004a17f8	d901	FLD float ptr [ECX]
004a17fa	d84804	FMUL float ptr [EAX + 0x4]
004a17fd	dec1	FADDP
004a17ff	d94034	FLD float ptr [EAX + 0x34]
004a1802	d8490c	FMUL float ptr [ECX + 0xc]
004a1805	dec1	FADDP
004a1807	d95a04	FSTP float ptr [EDX + 0x4]
004a180a	d94028	FLD float ptr [EAX + 0x28]
004a180d	d84908	FMUL float ptr [ECX + 0x8]
004a1810	d94104	FLD float ptr [ECX + 0x4]
004a1813	d84818	FMUL float ptr [EAX + 0x18]
004a1816	dec1	FADDP
004a1818	d94008	FLD float ptr [EAX + 0x8]
004a181b	d809	FMUL float ptr [ECX]
004a181d	dec1	FADDP
004a181f	d94038	FLD float ptr [EAX + 0x38]
004a1822	d8490c	FMUL float ptr [ECX + 0xc]
004a1825	dec1	FADDP
004a1827	d95a08	FSTP float ptr [EDX + 0x8]
004a182a	d9410c	FLD float ptr [ECX + 0xc]
004a182d	d8483c	FMUL float ptr [EAX + 0x3c]
004a1830	d94104	FLD float ptr [ECX + 0x4]
004a1833	d8481c	FMUL float ptr [EAX + 0x1c]
004a1836	dec1	FADDP
004a1838	d9402c	FLD float ptr [EAX + 0x2c]
004a183b	d84908	FMUL float ptr [ECX + 0x8]
004a183e	dec1	FADDP
004a1840	d9400c	FLD float ptr [EAX + 0xc]
004a1843	d809	FMUL float ptr [ECX]
004a1845	dec1	FADDP
004a1847	d95a0c	FSTP float ptr [EDX + 0xc]
004a184a	d94114	FLD float ptr [ECX + 0x14]
004a184d	d84810	FMUL float ptr [EAX + 0x10]
004a1850	d9411c	FLD float ptr [ECX + 0x1c]
004a1853	d84830	FMUL float ptr [EAX + 0x30]
004a1856	dec1	FADDP
004a1858	d94020	FLD float ptr [EAX + 0x20]
004a185b	d84918	FMUL float ptr [ECX + 0x18]
004a185e	dec1	FADDP
004a1860	d94110	FLD float ptr [ECX + 0x10]
004a1863	d808	FMUL float ptr [EAX]
004a1865	dec1	FADDP
004a1867	d95a10	FSTP float ptr [EDX + 0x10]
004a186a	d94014	FLD float ptr [EAX + 0x14]
004a186d	d84914	FMUL float ptr [ECX + 0x14]
004a1870	d94110	FLD float ptr [ECX + 0x10]
004a1873	d84804	FMUL float ptr [EAX + 0x4]
004a1876	dec1	FADDP
004a1878	d94034	FLD float ptr [EAX + 0x34]
004a187b	d8491c	FMUL float ptr [ECX + 0x1c]
004a187e	dec1	FADDP
004a1880	d94024	FLD float ptr [EAX + 0x24]
004a1883	d84918	FMUL float ptr [ECX + 0x18]
004a1886	dec1	FADDP
004a1888	d95a14	FSTP float ptr [EDX + 0x14]
004a188b	d94114	FLD float ptr [ECX + 0x14]
004a188e	d84818	FMUL float ptr [EAX + 0x18]
004a1891	d94038	FLD float ptr [EAX + 0x38]
004a1894	d8491c	FMUL float ptr [ECX + 0x1c]
004a1897	dec1	FADDP
004a1899	d94028	FLD float ptr [EAX + 0x28]
004a189c	d84918	FMUL float ptr [ECX + 0x18]
004a189f	dec1	FADDP
004a18a1	d94110	FLD float ptr [ECX + 0x10]
004a18a4	d84808	FMUL float ptr [EAX + 0x8]
004a18a7	dec1	FADDP
004a18a9	d95a18	FSTP float ptr [EDX + 0x18]
004a18ac	d94110	FLD float ptr [ECX + 0x10]
004a18af	d8480c	FMUL float ptr [EAX + 0xc]
004a18b2	d9411c	FLD float ptr [ECX + 0x1c]
004a18b5	d8483c	FMUL float ptr [EAX + 0x3c]
004a18b8	dec1	FADDP
004a18ba	d94118	FLD float ptr [ECX + 0x18]
004a18bd	d8482c	FMUL float ptr [EAX + 0x2c]
004a18c0	dec1	FADDP
004a18c2	d94114	FLD float ptr [ECX + 0x14]
004a18c5	d8481c	FMUL float ptr [EAX + 0x1c]
004a18c8	dec1	FADDP
004a18ca	d95a1c	FSTP float ptr [EDX + 0x1c]
004a18cd	d94124	FLD float ptr [ECX + 0x24]
004a18d0	d84810	FMUL float ptr [EAX + 0x10]
004a18d3	d9412c	FLD float ptr [ECX + 0x2c]
004a18d6	d84830	FMUL float ptr [EAX + 0x30]
004a18d9	dec1	FADDP
004a18db	d94020	FLD float ptr [EAX + 0x20]
004a18de	d84928	FMUL float ptr [ECX + 0x28]
004a18e1	dec1	FADDP
004a18e3	d94120	FLD float ptr [ECX + 0x20]
004a18e6	d808	FMUL float ptr [EAX]
004a18e8	dec1	FADDP
004a18ea	d95a20	FSTP float ptr [EDX + 0x20]
004a18ed	d94014	FLD float ptr [EAX + 0x14]
004a18f0	d84924	FMUL float ptr [ECX + 0x24]
004a18f3	d94120	FLD float ptr [ECX + 0x20]
004a18f6	d84804	FMUL float ptr [EAX + 0x4]
004a18f9	dec1	FADDP
004a18fb	d94034	FLD float ptr [EAX + 0x34]
004a18fe	d8492c	FMUL float ptr [ECX + 0x2c]
004a1901	dec1	FADDP
004a1903	d94024	FLD float ptr [EAX + 0x24]
004a1906	d84928	FMUL float ptr [ECX + 0x28]
004a1909	dec1	FADDP
004a190b	d95a24	FSTP float ptr [EDX + 0x24]
004a190e	d94124	FLD float ptr [ECX + 0x24]
004a1911	d84818	FMUL float ptr [EAX + 0x18]
004a1914	d94038	FLD float ptr [EAX + 0x38]
004a1917	d8492c	FMUL float ptr [ECX + 0x2c]
004a191a	dec1	FADDP
004a191c	d94028	FLD float ptr [EAX + 0x28]
004a191f	d84928	FMUL float ptr [ECX + 0x28]
004a1922	dec1	FADDP
004a1924	d94120	FLD float ptr [ECX + 0x20]
004a1927	d84808	FMUL float ptr [EAX + 0x8]
004a192a	dec1	FADDP
004a192c	d95a28	FSTP float ptr [EDX + 0x28]
004a192f	d94120	FLD float ptr [ECX + 0x20]
004a1932	d8480c	FMUL float ptr [EAX + 0xc]
004a1935	d9412c	FLD float ptr [ECX + 0x2c]
004a1938	d8483c	FMUL float ptr [EAX + 0x3c]
004a193b	dec1	FADDP
004a193d	d94128	FLD float ptr [ECX + 0x28]
004a1940	d8482c	FMUL float ptr [EAX + 0x2c]
004a1943	dec1	FADDP
004a1945	d94124	FLD float ptr [ECX + 0x24]
004a1948	d8481c	FMUL float ptr [EAX + 0x1c]
004a194b	dec1	FADDP
004a194d	d95a2c	FSTP float ptr [EDX + 0x2c]
004a1950	d94134	FLD float ptr [ECX + 0x34]
004a1953	d84810	FMUL float ptr [EAX + 0x10]
004a1956	d9413c	FLD float ptr [ECX + 0x3c]
004a1959	d84830	FMUL float ptr [EAX + 0x30]
004a195c	dec1	FADDP
004a195e	d94020	FLD float ptr [EAX + 0x20]
004a1961	d84938	FMUL float ptr [ECX + 0x38]
004a1964	dec1	FADDP
004a1966	d94130	FLD float ptr [ECX + 0x30]
004a1969	d808	FMUL float ptr [EAX]
004a196b	dec1	FADDP
004a196d	d95a30	FSTP float ptr [EDX + 0x30]
004a1970	d94014	FLD float ptr [EAX + 0x14]
004a1973	d84934	FMUL float ptr [ECX + 0x34]
004a1976	d94130	FLD float ptr [ECX + 0x30]
004a1979	d84804	FMUL float ptr [EAX + 0x4]
004a197c	dec1	FADDP
004a197e	d94034	FLD float ptr [EAX + 0x34]
004a1981	d8493c	FMUL float ptr [ECX + 0x3c]
004a1984	dec1	FADDP
004a1986	d94024	FLD float ptr [EAX + 0x24]
004a1989	d84938	FMUL float ptr [ECX + 0x38]
004a198c	dec1	FADDP
004a198e	d95a34	FSTP float ptr [EDX + 0x34]
004a1991	d94134	FLD float ptr [ECX + 0x34]
004a1994	d84818	FMUL float ptr [EAX + 0x18]
004a1997	d94038	FLD float ptr [EAX + 0x38]
004a199a	d8493c	FMUL float ptr [ECX + 0x3c]
004a199d	dec1	FADDP
004a199f	d94028	FLD float ptr [EAX + 0x28]
004a19a2	d84938	FMUL float ptr [ECX + 0x38]
004a19a5	dec1	FADDP
004a19a7	d94130	FLD float ptr [ECX + 0x30]
004a19aa	d84808	FMUL float ptr [EAX + 0x8]
004a19ad	dec1	FADDP
004a19af	d95a38	FSTP float ptr [EDX + 0x38]
004a19b2	d94130	FLD float ptr [ECX + 0x30]
004a19b5	d8480c	FMUL float ptr [EAX + 0xc]
004a19b8	d9413c	FLD float ptr [ECX + 0x3c]
004a19bb	d8483c	FMUL float ptr [EAX + 0x3c]
004a19be	dec1	FADDP
004a19c0	d94138	FLD float ptr [ECX + 0x38]
004a19c3	d8482c	FMUL float ptr [EAX + 0x2c]
004a19c6	dec1	FADDP
004a19c8	d94134	FLD float ptr [ECX + 0x34]
004a19cb	d8481c	FMUL float ptr [EAX + 0x1c]
004a19ce	dec1	FADDP
004a19d0	d95a3c	FSTP float ptr [EDX + 0x3c]
004a19d3	c3	RET
