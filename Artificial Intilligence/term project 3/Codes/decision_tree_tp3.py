# Import the necessary libraries
import numpy
import seaborn as sns
import matplotlib.pyplot as plot
import pandas
from sklearn import metrics
from sklearn.model_selection import train_test_split
from sklearn.model_selection import ShuffleSplit
from sklearn.model_selection import KFold
from sklearn.metrics import accuracy_score
from sklearn.tree import DecisionTreeRegressor

# Import the dataset
dataset = pandas.read_csv('BostonHousing.csv')

#Explore the dataset
print(dataset.shape) 
print(dataset.head(5))

# Differentiate attribute and target columns 
Y = dataset['medv'].values
X = dataset[['rm','ptratio','lstat']].values

predicted_y = []
expected_y = []

#Applying K-fold cross validation
kf = KFold(n_splits=4,shuffle=True)
for train_index, test_index in kf.split(X):
    x_train, x_test = X[train_index], X[test_index]
    y_train, y_test = Y[train_index], Y[test_index]
    
    regressor = DecisionTreeRegressor()
    regressor.fit(x_train, y_train)
    
    predicted_y.extend(regressor.predict(x_test))
    expected_y.extend(y_test)
    
df = pandas.DataFrame({'Actual': expected_y, 'Predicted': predicted_y})
print(df.head(20))

#showing bar chart
df1 = df.head(30)
df1.plot(kind='bar')
plot.show()

#showing plot
x_ax = range(len(expected_y))
plot.scatter(x_ax, expected_y, s=5, color="blue", label="original")
plot.plot(x_ax, predicted_y, lw=0.8, color="red", label="predicted")
plot.legend()
plot.show()

print('\nMean Absolute Error:', metrics.mean_absolute_error(expected_y, predicted_y))
print('Median Absolute Error:', metrics.median_absolute_error(expected_y, predicted_y))  
print('Mean Squared Error:', metrics.mean_squared_error(expected_y, predicted_y) )  
print('Root Mean Squared Error:', numpy.sqrt(metrics.mean_squared_error(expected_y, predicted_y)))


