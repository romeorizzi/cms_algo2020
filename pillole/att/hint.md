# Some hints on the pillole problem

To solve the problem pillole you need to apply inductive thinking.

What the hell is this?

In short: the ability to design a suiteble family of problems closed under induction.

Closed under induction means that they will all easily fall one after the other.
Of course, we also want the original problem to be contained in this familiy (or to easily reduce to problems in the family).

In case you are stuck in your attempts to solve this problem, we offer a longer explanation. It will always be your own responsability to make use of these hint files in the most productive way. Problems are meant to offer you an opportunity to acquire a competence and or general methodology. Do not spoil these opportunities. Stop reading every time you feel you might have something to try out yourself. And read the whole of the hint file when you have got full score and believe you know everything, not inasmatch to just make sure of anything in particular, but rather to profit of the occasion of a comparison and exchange.

An instance of problem pillole is a number $N$ that you get in input.
You must answer to this input $N$ by returning in output the number $f(N)$ of possible different ways to take your half pill every day.
As such, problem pillole already comprises many different questions, one for each possible value of $N$.
These corresponf to the instances of the problem you have been asked to solve with this exercise.

Broadly speaking, adopting the inductive approach means that, instead of posing yourself the single question corresponding to the $N$ you have received in input, you settle to answer the same general question for each one of the $N'\leq N$.
It might appear absurd at first to go for something bigger, solving all these instances rather than just one. However, since you are asked to design a method or machine that answers question $N$, it is rather reasonable that with $N$ calls to the machine each one of these answers will be in your hands.
Therefore, at least we are not hurting ourselves for sure with this higher ambition. As we will discover, setting for this higher ambition ususally puts us in the proper pespective on the problem.
Actually, to get a feeling for the problem, we suggest that you try solving the questions for small values of $N$ first. 
This might seem crazy at first, but since the hope is that the value of $f(N)$ can be easily reconstructed once the values $f(0), f(1), ..., f(n-1)$ are already perfectly known to us, you better put your hands at it as soon as possible.

According to the inductive approach, we break the problem as soon as we discover in which way $f(n)$ breakes down in term of $f(0), f(1), ..., f(n-1)$.
Indeed, we aim to reduce question $N$ in terms of smaller questions of the same kind.

Finding this golden link that opens the problem and breaks it up into pieces requires looking at the problem into his eyes (take the bull by the horns), and is a form of art that nobody can exhaust but there is a lot to learn about. We can grow this competence quite a bit.

Have a shot yourself to the problem. If you fail, come back here. (How many times as you want, we will be waiting here in full patience).

What could be a natural way to proceed here on this problem?
Notice for example that the total weight of the flask is bound to decrease every day.
Each day the flask will become lighter by half a pill. We could therefore limit ourself to ask wonder what might happen the very first day, and leave as a smaller problem all what follows. As usual, laziness is one of the biggest virtues that sets up a mathematician. Following this wise prescription, we will get one subproblem for each one possibility of what happens the very fist day.
With problem pillole the situation is here rather simple:
there is only one possibility for what might happen the very first day:
for sure it will be a whole pill to get extracted from the flask at first.
This pill gets split in two halves, one half is eaten and disappers from the game, and one half pill goes back to the flask. This flask is what we would like to deliver to induction.

Cast in terms of a recursive procedure, the first day we are going to make one single child. Actually, we can leave the subproblem to directly answer in our place (tail recursion). Indeed, the numbers of ways to empty a flask of $N$ pills is in all equal to the number of ways to empty one single flask with $N-1$ pills and $1$ half-pill.
We should now look at this new flask as the smaller problem which you left over for the next days to come. It should not be out businness to empty this task today, the doctor wouldn't be happy with that. Rather, we expect this flask to have been already solved by our magic helpers which induction effectively generates for us and places at our disposal.

Following this advice, at least in the very first step, the original problem gets reduced to one single question. This is a kind of simplicity which is actually not needed for the magic of induction to work, since we can ask for as many servants as we need in this roses' palace. We are then pretty ready to give it away in case of need. Indeed, tail recursion is actually rather unusual and we do not expect to have it here since in certain days we will be given the choice between two rather non-isomorphic choices. As examples of tail recursion consider computing the numbers of different ways to set up $N$ bits, or the powers of two (which atually share the same golden key), or the numbers of ways to sort $N$ items).

But there is still one big difficulty here with the problem pillole: we have reduced the original question $N$ to one question regarding a smaller flask, where by smaller we mean that the total mass in pills has got reduced, however this has introduced half pills and moved the problem outside the original familiy of questions that we were asked to answer all.

Indeed, the number of ways to empty one single flask with $N-1$ pills and $1$ half-pill does neither appear in the sequence $f(N-1), f(N-2), ..., f(1)$ nor breaks down to some of these in an easy way (if you adventured into that, there must be an easier way to solve such a simple problem).
The bare truth is: we have not yet got the golden key on this problem.
The problem is that the left-over problems (this time just one) have not ben successfully mapped into subproblems of the same family yet.

If the mountain will not come to Muhammad, then Muhammad must go to the mountain.

This is to say: if you want to be a problem solver, please, do not be harsh with the nature of problems, since the key to success and happiness is in getting into the nature of things with harmony.

To achieve this on this problem, after haing eaten your half pill prescribed by the doctor, rather than breaking up the problem any further with force, you should first have more faith in the magic and the powers of induction.

## The recursive decomposition algorithm

You are asking how? Are you still back following us after your authonomous attempts?

Yes, you are right: Unfortunately, the situation of the flask is not fully captured by just the number of whole pills contained into it. Indeed, on every odd day the flask will contain at least one half pill for sure.
You better accept this.
If we are in search of the ways of simplicity, and search for our way within the nature of the problem itself,the bare truth is that, day after day,
this process generates situations of the flask in which pill halves may be present, hence posing subproblems which fall outside the original form in which the problem had been posed to us at first. These would be better described by two paramenters (not only the number of whole pills but also the number of half pills). The key to get to a clean solution of this problem is in first generalizing its formulation according to ist nature.

Want to compare the solution you have got to against ours?

So, if a certain day we are given a flask with $N$ whole pills and $K$ half pills, then this is the way we are going to decompose our problem with the choice of the very first evening:
1. if the flask contains no whole pill (i.e., $N=0$), then we actually have no choice. No way we will ever extract a whole pill out of this flask, neither on the very first day, nor actually ever.
2. otherwise, if the flask contains no half pill ($K=0$, $N>0$) then again we have no choice: in our first day we necessarily pick a whole pill, and leave one single flask with $N-1$ whole pills and $K=1$ half pills to our magic helper elves which finish the job for us at night (we only have to suggest the meta-plan to them, find out the decomposition scheme for the problem, grab the golden key). 
3. otherwise yet, if both $K$ and $N$ are bigger than $0$, we actually have two possible options. Indeed, we could:
    + (3.a.) either pick one whole pill and leave to the elves one flask with $N-1$ whole pills and $K+1$ half pills;
    + (3.b.) or pick one half pill and leave to the elves one flask with $N$ whole pills and $K-1$ half pills.

When just computing our final answer, in Case 3 above we are then down to sum up two numbers provided to us by two different magic helpers.
In Case 1 we can either let a magic helper to answer in our place (tail recursion), or just answer 1 immidiately.
In Case 2 we go for a tail recursion (single child recursion).

## A word on base cases.

In general,

1. base cases is where the golden key does not enter into the keyhole (the main decomposition idea does not apply). 
2. we strive to make our base cases as small as possible, both to achieve generality and to achieve simplicity.

Here, the first principle suggests that $(N=0,K)$ should all be base cases.
However, $(N,K=0)$ do not candidate for base cases since these are already too interesting to be left over. Indeed, the original question of the problem falls within this second family.
Therefore, $f(N,K=0) = f(N-1,K=1)$ is one key we are going to be using.
Let's call it our silver key (still a rather nobel metal, isn't it?).

The second principle asks us to treat also $(N=0,K=0)$ as a special case, there is no reasono to let that out.
But what is the best answer for the $(N=0,K=0)$ subproblem in the family we have designed?

Well, it is so small that it is only fair to begin admitting that it goes subject to free interpretation, at least to a certain extent.

But here is another general principle that is only wise to follow:

apply the golden key.

In this case, consider that you would rather prefer it to work correctly whenever it enters into the keyhole.
Therefore, you want the following silver key identity to hold:

$f(N=1,K=0) = f(N=0,K=0)$

What is then our preferred value for $f(N=0,K=0)$?



