# ROS1

This is an Airport Runway Operating System designed to support and enhance airport operations from landside to airside, from landing to take off which simulate basic functionalities of an OS.

//////////////////////////////
Landing Scheduling: Jaineel
staff maintenence:Shlok
Landing protocol: Vvyom
Interupt handling : Aditya
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

