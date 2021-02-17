from bs4 import BeautifulSoup as bs
import requests as req
import re

cat=[]
vidCardType= []
container = []

my_url='https://www.newegg.com/Video-Cards-Video-Devices/Category/ID-38?Tpk=graphics%20card'
source = req.get(my_url).text

soup = bs(source, 'lxml') #use html.parser

summary = soup.find('body')
subject = summary.h1.text


for cats in summary.find_all('div', class_='nav-x-cell'):
    cat.append(cats.text.strip())
    

vidCardType_head = summary.h2.text
for vidCardTypes in summary.find_all('div', class_='dynamic-module-title'):
    vidCardType.append(vidCardTypes.text.strip())

listOfItems = summary.find_all('div', class_='standard-box-top')[1].h2.text

for graphicContainer in summary.find_all("div", {'class':'item-container'}):
    modelName = graphicContainer.img['title']
    container.append(modelName)
    
    try:
        promoOffer = graphicContainer.p.text   
    except Exception:
        promoOffer = 'NA'
    container.append(promoOffer)

    item_info = graphicContainer.find('div', class_='item-info')
    modelBrand = item_info.div.img['title']
    container.append(modelBrand)
    
    try:
        modelRating = item_info.div.i['class'][1]
    except Exception:
        modelRating = 'NA'
    container.append(modelRating)
    
    try:
        modelReview = re.search('\d+',item_info.div.span.text).group()
    except Exception:
        modelReview = 'NA'
    container.append(modelReview)
    
    try:    
        modelFeatures = item_info.ul.text.strip()
    except Exception:
        modelFeatures = 'NA'
    container.append(modelFeatures)
    
    item_action = graphicContainer.find('div', class_='item-action')

    try:
        modelPrice = float(item_action.strong.text+item_action.sup.text)
    except Exception:
        modelPrice = 'NA'
    container.append(modelPrice)
    
    try:
        modelShipping = item_action.find('li', class_='price-ship').text.strip()
    except Exception:
        modelShipping = 'NA'
    container.append(modelShipping)    

print(container)
