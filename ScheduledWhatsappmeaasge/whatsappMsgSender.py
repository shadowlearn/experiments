#Schedule WhatsApp message as a reminder at a specific time
#This can be scheduled to be run at a particular time with windows task scheduling or using cron in linux
#One time login is required after which old profile can be used to skip login page 

from selenium import webdriver as web
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

# To Install drivers in cache
#driver = web.Opera(executable_path=OperaDriverManager().install())
#driver = web.Firefox(executable_path=GeckoDriverManager().install())
#driver = web.Chrome(ChromeDriverManager().install())

# '\U' this is considered as unicode so we have to escape 1st backslash.
# '\f' does not work as it considers some other characters.

profile = web.FirefoxProfile('Profile path where firefox profile was saved after taking 1st login')
driver = web.Firefox(profile)
driver.get('https://web.whatsapp.com')

msg = "*Messagw to be sent*"
sign = "--JarvisAssist"
receiver_name, attempt = "Group Name", 4

print("Hi this is jarvis message reminder...")
#WebDriverWait(driver, 30).until(EC.presence_of_element_located((By.ID , 'side')))
time.sleep(60)
                              
for i in range(attempt):
    try:
        find_reciever = driver.find_element_by_xpath('//span[@title="{0}"]'.format(receiver_name))
        break
    except Exception:
        print("Reciever Not Found....attempt {0}".format(i+1))
        if (i == 3):
            print("Reciever not found ...Number of attemts exceeded...")
        receiver_name=input("Enter reciever name again...\n")
        continue

#Saving Cookies after logging for 1st time
#pickle.dump(driver.get_cookies(), open(prof_path, "wb"))

find_reciever.click()

msg_box = driver.find_element_by_xpath('//div[@class="_3FRCZ copyable-text selectable-text"] [@contenteditable="true"] [@data-tab="1"]')
msg_box.send_keys(msg)
msg_box.send_keys(Keys.SHIFT + Keys.ENTER)
msg_box.send_keys(Keys.SPACE*140)
msg_box.send_keys(sign+Keys.ENTER)
driver.quit()
