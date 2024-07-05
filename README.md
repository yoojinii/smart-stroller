<div align="center">
<h1>[2024] 아두이노 스마트 유모차 </h1>

유모차 사용 중 발생할 수 있는 안전사고나 예측하지 못한 통제 불능 상황을 대비하기 위함과 부모의 편안한 외출을 위한 스마트 유모차를 개발하게 되었습니다!
</div>

## 🔍 개요
- 프로젝트 이름 : 스마트 유모차
- 프로젝트 개발 기간 : 2024.04.14 ~ 2024.06.11
- 개발 환경
  
  HW - 아두이노 우노, 서보모터, 저항, 초음파 센서, 압력 센서, dc모터, l298d 모터 쉴, 아두이노 골드 / Rc 카 키트

  SW - C (Arduino)

### 업무 분담 (팀 구성 - 본인 외 3명)
- 팀장 : 발표, 기능 2 (인체감지센서) 회로도 설계, 코드 작성
- 팀원 1 : 기능 2 (인체감지센서) 회로도 설계, 코드 작성
- 팀원 2 :  RC카 조립, 기능 1 회로도 설계, 코드 작성, PPT
- 팀원 3 (본인) : RC카 조립, 기능 1/2(초음파 센서) 회로도 설계, 코드 작성, PPT



## 🖥 프로젝트 기능
**기능 1 : 압력 센서를 활용한 자동 회전 기능**

유모차의 무게로 인한 유모차 조절에 많은 힘이 들어가므로 유모차 손잡이에 부착된 압력 센서를 통해 사용자의 힘을 감지하고, 더 많은 힘이 가해지는 방향으로 바퀴를 회전 시켜 유모차를 더 쉽게 회전할 수 있도록 함

유모차 사용자의 부담 완화 : 아이에게 필요한 짐을 운반하면서 유모차까지 밀어야 하는 보호자들의 체력을 위해 압력 센서 2개를 활용해 오른쪽/왼쪽을 구분하고 각 센서로 사용자의 힘을 감지해 더 많은 힘이 가해지는 방향으로 바퀴를 회전시켜 유모차를 더 쉽게 밀 수 있도록 함. 



**기능 2 : 초음파 감지 센서를 활용한 안전 기능**

초음파 센서를 활용해 사용자가 감지 되지 않으면 서보모터로 바퀴가 굴러가는 것을 막음

안전 사고 예방 : 유모차 사고는 손잡이를 놓치거나 유모차와의 거리가 멀어질 때 보호자의 실수로 인해 발생하는 경우가 많음. 이런 경우를 대비해 초음파 센서를 이용하여 보호자를 감지하고 특정 거리만큼 멀어지면 자동으로 바퀴가 잠기게 함. 




## 🔻 시연 영상
<https://www.youtube.com/shorts/yuYnPXcw64w>
