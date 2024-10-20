from selenium import webdriver
from selenium.webdriver.chrome.options import Options

# Configure options for incognito mode
options = Options()
options.add_argument("--incognito")
options.add_argument("--headless")  # Optional: Run in headless mode

# Initialize the browser with options
driver = webdriver.Chrome(options=options)

# Open a website
driver.get("https://example.com")

# Close the browser
#driver.quit()
