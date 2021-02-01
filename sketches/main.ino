#define echoPin 2
#define trigPin 3

bool previousResult = true;
long duration;

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    pinMode(4, OUTPUT);
}
void loop()
{

    duration = getDistance();
    int result = (((duration / 100) > 500) || ((duration / 100) < 10));
    // if the button state has changed,
    if ((result != previousResult))
    {
        // and it's currently pressed:
        if (result == true)
        {
            Serial.println(1);
        }
        //if not pressed
        else
        {
            Serial.println(0);
        }
    }
    previousResult = result;
    digitalWrite(4, result);
    delay(100);
}

long getDistance()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    return pulseIn(echoPin, HIGH);
}