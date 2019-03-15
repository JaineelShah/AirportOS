# ROS1

//////////////////////////////
Landing Scheduling: Jaineel
staff maintenence:Shlok
Landing protocol: Vvyom
Interupt handling : Aditya Salian
/////////////////////////////




plane requests to land()

locks runway()
{
	if false: reduce fuel && try again later
}

plane lands()

//4 offloading spots

plane heads to offloading spots()

Offloading begins()

passengers get into bus()
{
	round robin
}

plane staff gets down()
{
	used for banking algorithm
}

plane gets empty()

plane heads for refuelling()

plane hads for maintenence()
{
	staff loads //used for banking algorithm
}

plane checks if runway is avaialable()
{
	if false, then queue
}

Interupt()
{
	if VIP plane lands, preempt a normal plane and offload VIP plane
}

goto hanger()

