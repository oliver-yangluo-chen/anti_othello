#!/usr/bin/env python3
from base64 import b64decode
from gzip import decompress
data = b''
data += b'H4sIAK4Cp18C/+1ZWXPbyBF+x69oyw8AVhAtyfbGxQpdtdk4KVVsr8pWah8YFgvHUBwJV2'
data += b'EGglBa/vd09+AmKe/GyVv4QAEzPX3N1xdlvYTPMhQe1FkJkQhlJCLQGeRC3INM8UlvBWxk'
data += b'LF4A3Gx9bSsIsyx+Yb3EV6lAqtTWkAg/1XQuEKBEWBYirkGkYVHnGhlmBfhprbcyvfXw4F'
data += b'2pNO1mJEykWXm7RTG+JiXsCLb+gyBeiX8vwEdxqQplVio8KTabrGBBhfAj1o24zKyXuPlR'
data += b'kCLGEhmBylDlr6Kgo3HtQVRkOWSpgGwDpQLnhtT62UXNiHHiyxhioTXqSNv3aVYxq01Wpi'
data += b'RJqhnAr8KOYzIyj4WvRETWXEHop+ArhVbTCSSbu5b18sWrUhWvApm+EukD5Gh+lr62LJnk'
data += b'ZAJapcWjjmXQr8SxCLVEc9ulwk+jLGnfVN1taJkIy9oUWQKqDPIiC4XCuzCb11kuUg+ur6'
data += b'4/GBJd52RVs31TovIefPJzWvXgo1TaoutEnhDLRGrklNI1ZmmkZtbHq09XN+uvNz99uYEF'
data += b'XJw3Czf//PKZ3tvXX25++ojvl/ADDE+cwo/n3RKdsay/Xn35ipRLJ3r0otpFDxcQPZJMtP'
data += b'dWOGcX3mWzWk9X5YZIeWtl/XJ9jXye7Mqegx3YHn3hU2XvyJ6fs/RBoL2B0JUQaJAuyAvo'
data += b'UkJwEcnU14LEJMqKxAbyTK0xAhBODj7OkdyFs/fGXUsMBY/iYTW3AD+F0GWRgoNsiHh5vn'
data += b'LP6Nn2bdf1+vWLdv0C1zspBvqOvJtPmLNAFDwSYvtBiCdvt/ZS3qGkFfrUvrh8/ebtj396'
data += b'x2sXqxUZfJ0pyfAxwVRlZRzBJpY5ec2R3h26T1Esxxh2QY0Y9mtRzFgtJl4TsRNkfhHNG3'
data += b'gsew1JQY+0w285Z53vzB/DqPMYAWpyrnEb8Vd09St+zfIc4xETxwLwKpeGDZrCpAwKzyCA'
data += b'EGM4NMcGTFpipUXeo+XCg3duf4Q+j5jk8Jg8JcofkDfcNY/1iA6d9fjnc8LY4/vFO/pbm9'
data += b'caX+cQYOa5nx5gny0fvXoFiwXY9lgyffaPiXjvYOuQ/eNk8wyvRKSR4yA5oukbvJpL2eNk'
data += b'7uCUhaln1GzQx+QWY+TBj2W0TrIHoX4XSH43LJhxf6N0mw1cU8wSZC2vDVLEO7NSD1dWva'
data += b'2dM5DLas65VqalGO5PAY+YRkC0Sk+gwwp27ifV3KGPeNuywhiLAFwzgw+PIjQ8yHPrtUyl'
data += b'Xq8dJeKNB2ESkVc8CCr2Ti+M9me4jc7A7/FyUOFqUHWLuqjHWirtFxRLVBxm9OWMQcJcqF'
data += b'YgDdcIZ2MTWVZqeBpk8R08ofAd5lO1FXG8uClKQXeKGXNBRYWf8RC/HBBRFVILJ6jGW+gb'
data += b'ysZMQcXbcTlUsnt7GkwD/eGsser9sKjsg5q5IjCLNZ+zyd12L188hiLX8IH/YIZEZUCMue'
data += b'RYHDQ6pKeptlg0ijJNqWqcsEtO5vggdif2ccd+xgC2uos3rjC3TuV+cNWJukVyh1Ypof8r'
data += b'td1ZUxjsUm/O3g2EdAJmfAuNh5HDcZJNXKotAqBThX1OVO4oTnrdsTakmWYDxq5pUD6SgN'
data += b'fPtxjLFK9p1tTNVvEZ1dp8AD8Rq8NMbbvXUOksn2q4D/IeYXaEqk6ugrGjYiFy53x2ceSa'
data += b'ZloUCZd/5z85fY8V1JmCa4ImRLv1bXiUeeR3+OjTpQdtAzL/zmg3jtrYlLThyUjA8Eb2u2'
data += b'MYnuDnD8QmdXffDk1js/28/4677FZoLkEGKKN+6XvdZN/SAIG8J64phCpj4jHIXf99v7SG'
data += b'7QnnODE6/DGfHWAz9mUv3SAQTVNZOgBdmxRNTYOnpg7t5k9todoBVY/MOACiklvsJ8NoN8'
data += b'1gHOBuWyj/7ifiaIkMPKimdZHrNFXGflDCxLPx0TGRDLVDATMJOtZb8ZBAowFy5WGh2k0q'
data += b'blkUpg9FsvFWgl0LzqGThpO32KMLOO/9iTUV7Z/mMCY2oLWjN2ZMcQ/vvrVZw8O74u1zZ8'
data += b'Wb4VlSh9JjHyYBTu29Tg0eKOHjZO4MW7ve15iHTJ/FjbUdDJmnWLemhvJ5ctRgyEkMh4Q4'
data += b'HJMyvAN3NaxOTDuGOaeyxeh+l0MGq1mXIvailM+SzajMAdYt+0vkb0bvWbjNZIhWELG7R2'
data += b'zig8ODcG/OkL322CgPNvbJE7PenaBwHDv8iKLGLO41FHvo63rPMdcOhh7r7boHzUFrWPR+'
data += b'tjBuoq/JJRwLDxrTRs4+EBGn9KNAF9ZdruaidqC/bvpCXec8d3NXiJE83adb6zGzHA/rbj'
data += b'M08jV7d6joZH80KTKaB/3/EIrPDAFD6StoB6wDKWpJTAYU+8KH4J1hVJQYEBNp+axpDgwZ'
data += b'e2/QzakySfyiPlIFw6xMtXomVcrhHZNaWsai04ytOKKXYb0k+lV/1cOB8eQv86eGCpPVag'
data += b'e/9u8Vvp8MrNhm1ZqlHTGE99a4RKmZ0QABhBCBAGwFYItd8wHaUyY+PZt+Tofke/Pj2M4x'
data += b't/7nlpp/foHfYDy27M2nB34BGHIcoIUHdvp9wZ7Zzx+yJ0LHm799hzOau+tOWRZmyxgnRF'
data += b'Vj7iluH1x4v4BLYxSW/XVAKbjZW16srL7Bb3dlmpeUG4vstvAT/sm2TNlPQeyH93PAnHdQ'
data += b'yuueTzWUcjmVUj0rpdpiT2ekmBBirfrp3GFFm4LaUFT7FFVTVK1bbFdwm7oWp2XYZoo1zr'
data += b'q0P2s7AORoSgPPq3b7yjQD0GPCtsjxitsI1Dg25YnpuHw3ODJEXbjxPldgE8XHubeatr1X'
data += b'q2/XizV6/g3HoRiU1KVP2WKOBcywa/KM+4wJXX3nvbZkzQea2Z+u0BH/+EBsExRq/f+/Dv'
data += b'+b/zr8G0TCalvPGQAA'
exec(decompress(b64decode(data)).decode("utf-8"))