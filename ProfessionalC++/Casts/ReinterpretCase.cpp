class X {};
class Y {};

int main()
{
	X x;
	Y y;

	X* xp = &x;
	Y* yp = &y;

	xp = reinterpret_cast<X*>(yp);

	void* p = reinterpret_cast<void*>(xp);
	xp = reinterpret_cast<X*>(p);

	X& xr = x;
	Y& yr = reinterpret_cast<Y&>(x);

	return 0;
}
