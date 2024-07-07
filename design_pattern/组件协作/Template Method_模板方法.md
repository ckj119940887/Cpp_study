# Intro
```
在软件构建过程中，对于某一项任务，它常常有稳定的整体操作结构，但各个子步骤却有很多改变的需求，或者由于固有的原因（比如框架与应用之间的关系）而无法和任务的整体结构同时实现。

在该模式中，首先要明确框架中的稳定操作，这里的稳定操作指的是相对稳定，并不是绝对的稳定。
```

# demo
## 修改前
```
//程序库开发人员
class Library {
public:
	void step1() {
	
	}
	
	void step3() {
	
	}
	
	void step5() {
	
	}
};

//应用开发人员
class Application {
public:
	bool step2() {
	
	}
	
	bool step4() {
	
	}
};

//既要调用library的实现，也要调用app的实现
int main() {
	Library lib();
	Application app();
	
	lib.step1();
	
	if(app.step2()) {
		lib.step3();
	}
	
	for(int i = 0; i < 4; i++)
	{
		app.step4();
	}
	
	lib.step5();
}
```

## 修改后
```
//程序库开发人员
class Library {
	//稳定 template method
	//run()方法是稳定的，即基本流程是稳定的，不易变的
	void run() {
		step1();
	
		if(step2()) {
			step3();
		}
		
		for(int i = 0; i < 4; i++)
		{
			step4();
		}
		
		step5();
	}
	
	virtual ~Library() {}

protected:
	void step1() {
	
	}
	
	void step3() {
	
	}
	
	void step5() {
	
	}
	
	//留给应用开发人员重写
	virtual bool step2() = 0;
	virtual void step4() = 0;
};

//应用开发人员
class Application : public Library {
public:
	virtual bool step2() {
	
	}
	
	virtual void step4() {
	
	}
};

int main() {
	//使用多态指针
	Library* pLib = new Application();
	pLib->Run();
}
```

# 早绑定 VS. 晚绑定
```
Library与Application的关系：
早绑定：Application调用Library。
晚绑定：Library决定所有的流程，由Library来调用Application，这里的Application是由应用开发者来定制的。即Library已经决定了整体的流程，而其中有些步骤是由Application场景定制的。

这里的整体流程就是稳定的，其中可定制的部分是易变的。易变的部分就是纯虚函数，由应用开发者来决定。

Template Method模式是一种非常基础性的设计模式，在面向对象系统中有着大量的应用。它用最简洁的机制（虚函数的多态性）为很多应用程序框架提供了灵活的扩展点，是代码复用方面的基本实现结构。

在具体实现方面，被Template Method调用的虚方法可以具有实现，也可以没有任何实现（抽象方法、纯虚方法），但一般推荐将它们设置为protected方法(这些方法通常是整体流程的步骤，而不是用来被外界进行调用)。
```
