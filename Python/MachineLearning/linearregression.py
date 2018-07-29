import pandas as pd
import quandl
quandl.ApiConfig.api_key = 'szgGA1SsysWYmb59TpGT'

df = quandl.get("WIKI/GOOGL")

print(df.head())
