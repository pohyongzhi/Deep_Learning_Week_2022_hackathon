#This is the python program in the raspberry pi for hardware sensors that we are going to use for our prototype

#Importation of modules and packages
import time
import grovepi

def main():
    # declaring of variables
    buzzer_pin = 2		#Port for buzzer
    ultrasonic = 4		#Port for ultrasonic

    # Assign mode for buzzer as output
    pinMode(buzzer_pin,"OUTPUT")
    # Assign mode for ultrasonic as input
    pinMode(ultrasonic,"INPUT")
    #when the prototype is being activated	
    while True:
        #exception handling to validate conditions
        try:
            #Read the ultrasonic status
            ultrasonic_status= digitalRead(ultrasonic)
            #If the ultrasonic is in HIGH position, run the program
            if ultrasonic_status:
                 # display "\tBuzzing"	
                digitalWrite(buzzer_pin,1)							
            #If ultrasonic is in Off position, print "Off" on the screen
            else:		
                 # print "Off"
                digitalWrite(buzzer_pin,0)			
        # Stop the buzzer before stopping
        except KeyboardInterrupt:
            digitalWrite(buzzer_pin,0)
            break
        except (IOError,TypeError) as e:
            print("Error")

if __name__ == "__main__":
    main()