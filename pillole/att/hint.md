# Some hints on problem `pills`

To solve problem `pills` you need to apply inductive thinking.

What the hell is this?

In short: the ability to design a suitable family of problems closed under induction.


Closed under induction means that they will all easily fall one after the other.

Of course, we also want the original problem to fall within this family (or to be easily reducible to problems of the family).

## Managing more hints

In case you are stuck in your attempts to solve this problem, we offer a longer explanation. It will always be your own responsibility to make use of these hint files in the most productive way. Problems offer an opportunity to acquire a competence or grab a general methodology. Do not spoil them for yourself. Stop reading every time you feel you might have something to try out yourself. And read these entire hint files once you have got full score and believe you know everything, not inasmuch to just make sure of anything in particular, but rather to profit of the occasion of a comparison and exchange.

## Problems and instances

An instance of problem `pills` is a number $N$ that you get in input.

You must answer to this input $N$ by returning in output the number $f(N)$ of possible different ways to take your half pill every day.

As such, problem `pills` already comprises many different questions, one for each possible value of $N$. That is, one for every possible instance of the problem.

Each of these questions/instances can be encoded as a single natural number. Yes, we are in the realm of concrete mathematics, the field of mathematics encompassing computer science. The garden of Induction Queen that rules over these lands. 

## Induction as an active competence

Broadly speaking, adopting the inductive approach means that, instead of posing yourself the single question corresponding to the $N$ you have received in input, you settle to answer the same general question for each one of the $N'\leq N$. This, after all, is the high algorithmic ambition of the exercise.

It might seem absurd at first to go for something bigger, solving all of these instances and each of the questions with $N'\leq N$, rather than just the single posed one. However, since you are asked to design a method or machine that answers question $N$, it can also be anticipated that with just $N$ calls to the machine each one of these answers will anyhow be already in your hands. You are not really rising the true ambition and requirement of the exercise. Therefore, at least we are not hurting ourselves for sure with this higher ambition. As we will discover, setting for this higher ambition usually puts us in the proper perspective on the problem.

## Put your hands into the problem

Actually, to get a feeling for the problem, we suggest that you try solving the questions for small values of $N$ first. 

This might seem crazy at first, but since the hope is that the value of $f(N)$ can be easily reconstructed once the values $f(0), f(1), ..., f(n-1)$ are already perfectly known to us, you better put your hands at it as soon as possible.

According to the inductive approach, we break the problem as soon as we discover in which way $f(n)$ breaks down in term of $f(0), f(1), ..., f(n-1)$. Indeed, we aim to reduce question $N$ to smaller questions of the same kind, rephrasing it in terms of these.

Finding this golden link that opens the problem and breaks it up into pieces requires looking at the problem into his eyes (take the bull by the horns), and is a form of art that nobody can exhaust but there is a lot to learn about. We can grow this competence quite a bit.

Have a shot yourself to the problem. If you fail, come back here. (How many times as you want, we will be waiting here in full patience).


## What could be a natural way to proceed here on this problem?

Notice that the total weight of the flask is bound to decrease every day. The weight of the flask (essentially a natural number if you take half a pill as your unit) can well play as the measure for the size of the problem within an inductive approach.

Each day the flask becomes lighter by half a pill. We could therefore limit ourself to wonder what might happen the very first day, and leave as a smaller problem all what follows. Che serà serà ... . As usual, laziness is one of the biggest virtues that sets up a mathematician. Following this wise prescription, we will get one subproblem for each one possibility of what happens the very fist day.

With problem `pills` the situation is here rather simple. Indeed, there is one single possibility for what might happen on the very first day: for sure it will be a whole pill to get extracted from the flask when it contains no half pill.

According to the process, this whole pill gets split in two halves, one half is eaten and disappears from the game, and one half pill goes back to the flask. This flask is what we would like to deliver to induction.

## When more generality is called for

This only child is rather fishy, we do not expect to have one single choice in every day of the cure. It might be that the original family of instances is not wide enough to encompass all possible situations. We must abstract to the true general form of the problem in order to advance and break through its stucture. After all, induction takes often the form of an exquisite form of abstraction.

But let's get to this gradually. Cast in terms of a recursive procedure, the first day we are going to make one single child. Actually, we can leave the subproblem to directly answer in our place (tail recursion). Indeed, the numbers of ways to empty a flask of $N$ pills is in all equal to the number of ways to empty one single flask with $N-1$ pills and $1$ half-pill.

We should now look at this new flask as the smaller problem which you left over for the next days to come. It is already lighter than the flask we were given, and it should not be our business to empty the entire flask today, the doctor wouldn't be happy with that. Relax, do not overdo. Rather, we embrace a declarative top down approach and expect this flask to have been already solved by our magic helpers which induction effectively generates for us and places at our disposal. Here, top down and bottom up are the same and only subject to your preference. Once you know there is a ladder out there, then the competences of going up and down are complementary like writing and reading, and are better learned and experimented together in alternation.

Following this advice, at least in the very first step, the original problem gets reduced to one single question. This is a kind of simplicity which is actually not needed for the magic of induction to work, since we can ask for as many servants as we need in this palace set up for our learnig of proper timing and grace. One single call appears too poor for this problem, and we are pretty ready to give this benefit away in case of need since the true issue right now is still more about the albeit obvious decidability rather than efficiency. Indeed, tail recursion is actually rather unusual and we do not expect to have it here since in certain days we will be given the choice between two rather non-isomorphic choices. As examples of tail recursion consider computing the numbers of different ways to set up $N$ bits, or the powers of two (which actually share the same golden key), or the numbers of ways to sort $N$ items).

But there is still one big difficulty here with problem `pills`: we have reduced the original question $N$ to one question regarding a lighter flask. However, this has introduced half pills and moved the problem outside the original family of questions that we were asked to answer all.

Indeed, the number of ways to empty one single flask with $N-1$ pills and $1$ half-pill does neither appear in the sequence $f(N-1), f(N-2), ..., f(1)$ nor breaks down to some of these in an easy way (if you adventured into that, there must be an easier way to solve such a simple problem).

The bare truth is: we have not yet got the golden key on this problem.

The problem is that the left-over problems (this time just one) have not ben successfully mapped into subproblems of the same family yet.


If the mountain will not come to Muhammad, then Muhammad must go to the mountain.

This is to say: if you really want to solve problems, please, do not be harsh with the nature of problems, since the key to success and happiness is in getting into the nature of things with harmony.


To achieve this on this problem, after having eaten your half pill prescribed by the doctor, rather than breaking up the problem any further with force, you should first have more faith in the magic and the powers of induction.


## The recursive decomposition algorithm


You are asking how? Are you still back here, to follow us again after your autonomous attempts?


Yes, you are right: Unfortunately, the situation of the flask is not fully captured by just the number of whole pills contained into it. Indeed, on every odd day the flask will contain at least one half pill for sure.

You better accept this.

If we are in search of the ways of simplicity, following through the nature of the problem itself, the bare truth is:
day after day, this process generates situations of the flask in which pill halves may be present. These situations pose subproblems which fall outside the original form in which the problem had been posed to us at first, these do not correspond to the original problem's instances.
These subproblems would be better described by two parameters rather than just one; not only the number of whole pills but also the number of half pills should be accounted for if we want to split up the whole process into small and regular epochs. The key to get to a clean solution of this problem is in first generalizing its formulation according to ist nature.


## Want to compare the solution you have got to against ours?

So, if a certain day we are given a flask with $N$ whole pills and $K$ half pills, then this is the way we are going to decompose our problem with the choice of the very first evening:
1. if the flask contains no whole pill (i.e., $N=0$), then we actually have no choice. No way we will ever extract a whole pill out of this flask, neither on the very first day, nor actually ever.
2. otherwise, if the flask contains no half pill ($K=0$, $N>0$) then again we have no choice: in our first day we necessarily pick a whole pill, and leave one single flask with $N-1$ whole pills and $K=1$ half pills to our magic helper elves which finish the job for us at night (we only have to suggest the meta-plan to them, find out the decomposition scheme for the problem, grab the golden key). 
3. otherwise yet, if both $K$ and $N$ are bigger than $0$, we actually have two possible options. Indeed, we could:
    + (3.a.) either pick one whole pill and leave to the elves one flask with $N-1$ whole pills and $K+1$ half pills;
    + (3.b.) or pick one half pill and leave to the elves one flask with $N$ whole pills and $K-1$ half pills.

When just computing our final answer, in Case 3 above we are then down to sum up two numbers provided to us by two different magic helpers.
In Case 1 we can either let a magic helper to answer in our place (tail recursion), or just answer 1 immediately.
In Case 2 we go for a tail recursion (single child recursion).

## A word on base cases.

In general,

1. base cases is where the golden key does not enter into the keyhole (the main decomposition idea does not apply). 
2. we strive to make our base cases as small as possible, both to achieve generality and to achieve simplicity.

Here, the first principle suggests that $(N=0,K)$ should all be base cases.
However, $(N,K=0)$ do not candidate for base cases since these are already too interesting to be left over. Indeed, the original question of the problem falls within this second family.
Therefore, $f(N,K=0) = f(N-1,K=1)$ is one key we are going to be using.
Let's call it our silver key (still a rather nobel metal, isn't it?).

The second principle asks us to treat also $(N=0,K=0)$ as a special case, there is no reason to let that out.
But what is the best answer for the $(N=0,K=0)$ subproblem in the family we have designed?

Well, it is so small that it is only fair to begin admitting that it goes subject to free interpretation, at least to a certain extent.

But here is another general principle that is only wise to follow:

apply the golden key.

In this case, consider that you would rather prefer it to work correctly whenever it enters into the keyhole.
Therefore, you want the following silver key identity to hold:

$f(N=1,K=0) = f(N=0,K=0)$

What is then our preferred value for $f(N=0,K=0)$?



