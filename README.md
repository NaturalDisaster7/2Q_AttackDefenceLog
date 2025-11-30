## 게임 인재원 7기 2학기 리포지토리

게임명 : 검을 그리라 공방록  
기간 : 25.07.28 - 25.08.13  

장르 : 아케이드   
플레이 방식 : 3x3 보드에서 나오는 노드에 맞춰서 선을 그어 공격, 방어, 패링을 하여 적과 싸운다.

## 프로그래밍 팀원

| 참여자 | 역할 | 내용 |
| :---: | :---: | :---: |
| 한승규​  &nbsp;| 팀장, 게임 컨텐츠 개발 | 패턴 로직·브러쉬·연출·타이틀 씬·난이도 선택 등 게임플레이 컨텐츠 중심 작업 |
| 안성빈​  &nbsp;| 게임 전투 로직 개발 | StateComponent, 플레이어/적 구조, 연격 시스템, 배틀 매니저 등 전투 로직 핵심 요소 |
| 이성호​  &nbsp;| 게임 엔진 설계 및 유지 보수 / 시스템 기능 구현 | 파티클 컴포넌트, UI, 이미지/노드 자르기, delegate 기능, 스테이지 병합, 빌드 루프 관리 |
| 김정현​  &nbsp;| 게임 시스템 개발 | FMod 엔진, 카메라 시스템, csvLoader, 효과 시스템, UI 일부 등 엔진-게임 사이를 연결하는 시스템 기능 전반 담당 |


## 게임 플레이 영상

[![youtubelink](https://i.ytimg.com/vi/grB1i2tEdxs/hqdefault.jpg?s…GUgYihYMA8=&rs=AOn4CLDo2nqTZpLwqt1nDjPX9fr4IHhJiQ)](https://youtu.be/grB1i2tEdxs)

## 엔진 구조 

[원본 엔진 코드](https://github.com/mob954325/DirectX2D_2)

### 게임 루프
<img width="2951" height="1025" alt="GameLoop" src="https://github.com/user-attachments/assets/6d65db10-c547-45f9-a176-61771732c781" />

### 게임 오브젝트 루프
<img width="2391" height="1561" alt="GameObjectLoop" src="https://github.com/user-attachments/assets/c73053af-d705-4812-9abf-f215ff8f67ce" />

### 리소스 매니저
<img width="574" height="400" alt="ResourceManager1 drawio" src="https://github.com/user-attachments/assets/a33c9296-7a8d-4cae-b78d-40f7a1a06994" />

### 사용자 스크립트 
<img width="1642" height="481" alt="UserComponent" src="https://github.com/user-attachments/assets/7c2ee49a-aa0c-4cd4-91cf-00c8401bff6b" />

