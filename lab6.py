from tkinter import Y
import numpy as np
import matplotlib.pyplot as plt
def DifFinProg(X,Y):
          n= len(X)-2
          df =np.zeros(shape=n)
          for i in range(1, n+1):
                    df[i-1]=(Y[i+1]-Y[i])/(X[i+1]-X[i])
          return df

def DifFinReg(X, Y):
          n= len(X)-2
          df=np.zeros(shape=n)

          for i in range(1, n+1):
                    df[i-1]=(Y[i]-Y[i-1])/(X[i]-X[i-1])
          return df
def DifFinCent(X, Y):
          n=len(X)-2
          df=np.zeros(shape=n)
          for i in range(1, n+1):
                    df[i-1]= (Y[i+1]-Y[i-1])/ (X[i+1]-X[i-1])
          return df
def func1(x):
          y=np.sin(x)
          return y
def dfunc1(x):
          df= np.cos(x)
          return df

N = 100
domain = np.linspace(0,np.pi,N)
df_domain =  dfunc1(domain)

X_dom = np.full(shape=N+2, fill_value=np.nan)
X_dom[1:N+1] = np.linspace(0,np.pi,N)
h = X_dom[3] - X_dom[2]
X_dom[0] = X_dom[1] - h
X_dom[N+1] = X_dom[N] + h
Y_dom = func1(X_dom)

df_progresive = DifFinProg(X=X_dom, Y=Y_dom)
df_regresive = DifFinReg(X=X_dom,Y=Y_dom)
df_centrale = DifFinCent(X=X_dom, Y=Y_dom)

plt.figure(0)
plt.plot(domain, df_domain, c='k',label='df exacta')
plt.plot(X_dom[1:N+1], df_progresive,c='orange', label='df prog')
plt.plot(X_dom[1:N+1], df_regresive, c='g', label = 'df reg')
plt.plot(X_dom[1:N+1], df_centrale, c='r', label='df centrale')
plt.grid()
plt.xlabel('points')
plt.ylabel('df values')
plt.legend()
plt.title(f'Diferente finite pentru N={N}')
plt.show()

df_for_error = dfunc1(X_dom)
plt.figure(1)
plt.plot(X_dom[1:N+1],np.abs(df_progresive - df_for_error[1:N+1]), c='orange',label='df prog')
plt.plot(X_dom[1:N+1],np.abs(df_regresive - df_for_error[1:N+1]), c='b',label='df reg')
plt.plot(X_dom[1:N+1],np.abs(df_centrale - df_for_error[1:N+1]), c='r',label='df centrale')
plt.grid()
plt.xlabel('points')
plt.ylabel('Error values')
plt.legend()
plt.title(f'Eroarea diferentelor finite pentru N={N}')
plt.show()

def SplineL(X, Y, z):
    n= len(X)-1
    for i in range(n):
        if X[i]<=z <= X[i+1]:
            a= Y[i]
            b=(Y[i+1]-Y[i])/(X[i+1]-X[i])
            t= a+b*(z-X[i])

            break
    return t
domain = np.linspace(-np.pi/2, np.pi/2, 100)
f_values = func1(domain)
N = 10
X_domeniu = np.linspace(-np.pi/2, np.pi/2, N+1)
Y_domeniu = func1(X_domeniu)
Y_prim = dfunc1(X_domeniu)
f_spline_liniara = np.array([SplineL(X_domeniu, Y_domeniu, z) for z in domain])

plt.figure(2)
plt.scatter(X_domeniu, Y_domeniu, s=15, c="red", marker="*", label="Date cunoscute")
plt.plot(domain, f_spline_liniara, c='orange', label='spline liniara')
plt.grid()
plt.xlabel('points')
plt.ylabel('Values')
plt.legend()
plt.title(f'Interpolari pt N={N}')
plt.show()
def SplineP(X, Y, fpa,  z):
    n=len(X-1)
    b=np.zeros(shape=n)
    b[0]=dfunc1(-np.pi/2)
    for i in range(0, n-1):
         b[i+1] = 2/(X[i+1] - X[i]) * (Y[i+1] - Y[i]) - b[i]
    for i in range(n):
        if X[i] <= z <= X[i+1]:
            a = Y[i]
            c = (1/(X[i+1] - X[i])**2) * (Y[i+1] - Y[i] - (X[i+1] - X[i]) * b[i])
            t = a + b[i]*(z - X[i]) + c*(z-X[i])**2

            break

    return t
domain = np.linspace(-np.pi/2, np.pi/2, 100)
f_values = func1(domain)

N = 10
X_domeniu = np.linspace(-np.pi/2, np.pi/2, N+1)
Y_domeniu = func1(X_domeniu)
Y_prim = dfunc1(X_domeniu)

f_spline_patratica = np.array([SplineP(X_domeniu, Y_domeniu, Y_prim, z) for z in domain])


plt.figure(0)
plt.scatter(X_domeniu, Y_domeniu, s=15, c='red', marker='*', label='Date cunoscute')
plt.plot(domain, f_values, c='k', label='f exact')
plt.plot(domain, f_spline_patratica, c='orange', label='spline patratica')
plt.grid()
plt.xlabel('points')
plt.ylabel('Values')
plt.legend()
plt.title(f'Interpolari pentru N={N}')
plt.show()
