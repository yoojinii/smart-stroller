#define MOTOR_A_SPD 10  //모터A의 속력을 결정하는 핀
#define MOTOR_B_SPD 11  //모터B의 속력을 결정하는 핀
#define MOTOR_A_DIR 12  //모터A의 방향을 결정하는 핀
#define MOTOR_B_DIR 13  //모터B의 방향을 결정하는 핀
#define A_BAL 1   //모터A 속력 균형 계수 기본값 1
#define B_BAL 1   //모터B 속력 균형 계수 기본값 1
#define M_SPEED 150   //모터 속력

#define PRESSURE_SENSOR_LEFT A0  //왼쪽 압력 센서 핀
#define PRESSURE_SENSOR_RIGHT A1 //오른쪽 압력 센서 핀

unsigned char m_a_spd = 0, m_b_spd = 0; //모터의 속력을 결정하는 전역변수
boolean m_a_dir = 0, m_b_dir = 0; //모터의 방향을 결정하는 전역변수

void setup()  
{
  Serial.begin(9600); //시리얼 통신 초기화

  pinMode(MOTOR_A_DIR, OUTPUT); //모터A 방향 핀 출력으로 설정
  pinMode(MOTOR_B_DIR, OUTPUT); //모터B 방향 핀 출력으로 설정
  
  Serial.println("Hello!"); //터미널 작동 확인용 문자열
}

void loop()
{
  int pressure_left = analogRead(PRESSURE_SENSOR_LEFT);  //왼쪽 압력 센서 값 읽기
  int pressure_right = analogRead(PRESSURE_SENSOR_RIGHT); //오른쪽 압력 센서 값 읽기
  
  // 압력 센서 값 시리얼 모니터에 출력
  Serial.print("Pressure left: ");
  Serial.print(pressure_left);
  Serial.print("\t Pressure right: ");
  Serial.println(pressure_right);

  rc_ctrl_val(pressure_left, pressure_right);  //압력 센서 값에 따라 모터에 입력될 변수를 조정하는 함수
  motor_drive();  //모터를 구동하는 함수
}

void rc_ctrl_val(int left, int right) //압력 센서 값에 따라 모터에 입력될 변수를 조정하는 함수
{
  if(left >= 50 && right >= 50)  //양쪽 압력 센서 값이 모두 50 이상일 때, 전진
  {
    m_a_dir = 1;  //모터A 정방향
    m_b_dir = 1;  //모터B 정방향
    m_a_spd = M_SPEED * A_BAL;  //모터A의 M_SPEED의 PWM
    m_b_spd = M_SPEED * B_BAL;  //모터B의 M_SPEED의 PWM
  }
  else if(left >= right + 80)  //왼쪽 압력 센서 값이 오른쪽 압력 센서 값보다 80 이상 높을 때, 좌회전
  {
    m_a_dir = 0;  //모터A 역방향
    m_b_dir = 1;  //모터B 정방향
    m_a_spd = M_SPEED * A_BAL * 0.5;  //모터A의 M_SPEED의 PWM
    m_b_spd = M_SPEED * B_BAL*2;  //모터B의 M_SPEED의 PWM
  }
  else if(right >= left + 80)  //오른쪽 압력 센서 값이 왼쪽 압력 센서 값보다 80 이상 높을 때, 우회전
  {
    m_a_dir = 1;  //모터A 정방향
    m_b_dir = 0;  //모터B 역방향
    m_a_spd = M_SPEED * A_BAL*2;  //모터A의 M_SPEED의 PWM
    m_b_spd = M_SPEED * B_BAL * 0.5;  //모터B의 M_SPEED의 PWM

  }
  else  //모터 정지
  {
    m_a_spd = 0;  //모터A의 정지
    m_b_spd = 0;  //모터B의 정지
  }
}

void motor_drive()  //모터를 구동하는 함수
{
  digitalWrite(MOTOR_A_DIR, m_a_dir);  //모터A의 방향을 디지털 출력
  digitalWrite(MOTOR_B_DIR, m_b_dir);  //모터B의 방향을 디지털 출력
  analogWrite(MOTOR_A_SPD, m_a_spd);  //모터A의 속력을 PWM 출력
  analogWrite(MOTOR_B_SPD, m_b_spd);  //모터B의 속력을 PWM 출력
}
