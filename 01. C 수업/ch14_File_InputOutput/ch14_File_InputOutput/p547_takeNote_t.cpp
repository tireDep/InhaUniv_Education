/*

파일 시스템 : 파일 단위의 정보를 생성, 삭제, 저장, 검색할 수 있도록 정보를 구성하는 방법

절대 경로 : 디스크 볼륨 이름부터 파일명에 이르는 전체 정보를 표시한 것
상대경로 : 드라이브명과 폴더명을 생략하여 파일 이름만을 표시하는 것
		  상대 경로를 사용할 경우, 프로세스의 현재 경로를 기본 경로로 설정하여 파일의 논리적 위치를 결정

텍스트 파일 : ASCII코드나 문자열로 해석할 수 있는 정보들로 구성된 파일
			 -1이라는 정수값을 파일의 끝(EOF, End of File)로 인식함
바이너리(Binary) 파일 : 텍스트 파일을 제외한 모든 파일들은 바이너리 파일
==> 메모장에서 열리면 텍스트 파일, 안열리면 바이너리 파일

fopen() 함수의 접근 모드 문자열

*/