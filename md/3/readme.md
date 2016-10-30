# Kinyou_benkyokai-p 3

## UnityTutorialを英語で読もうの巻

## [Good Coding Practices in Unity](https://unity3d.com/jp/learn/tutorials/modules/intermediate/scripting/coding-practices?playlist=17117)

---

## 前回のアンケート結果

- unityの話
- 英語を頑張る

→英語でunity

※あんまりunityの話じゃない

※注 私の英語力は2です(10段階で)
直訳、誤訳が多い

---

It’s not something a lot of new developers to Unity think about, but it’s still an incredibly important topic. It’s about coding practices, and it can make your life much easier.

- developer　開発者
- increadibly 非常に
- make A B 　AをBにする

----

>これは、新しいUnityの開発者の多くが考えているものではありませんが、まだ非常に重要なトピックです。コーディングプラクティスについて、それはあなたの人生がとても楽にすることができます。

---

The idea behind coding practices is that you keep in mind a set of guidelines when you write your code. These guidelines are often designed to keep your code maintainable, extensible, and readable, which in turn helps reduce the pain of refactoring.

- behind ~の背後に
- keep in mind 留意する、覚えておく
- keep A B AをBの状態にしておく
- turn A B AをBの状態にする

----

>コーディングプラクティスの背後には、あなたがコードを書くときに一連のガイドラインを覚えておくという考え方があります。
これらのガイドラインは多くの場合、リファクタリングの辛さを減らすのに役立ち、あなたのコードの保守性、拡張性、リーダブルな状態を保つように作られています。

---

How many times have you wanted to change some code in your project, which turned out to be much harder than you thought because there’s a bunch of classes relying on that code – it’s like when you go to unplug your keyboard, and you find that the back of your computer is a horror-inducing tangled mess of cables and there’s almost no hope of picking out just the one.

- A is much ~er than B - AはBよりもずっと～です
- bunch of - メッチャ
- rely　依存する
- horror-inducing　恐ろしい気分にさせる
- pick out 見分ける、選ぶ

----

>あなたは何度プロジェクトのコードを変えたいと思い、そのコードに依存するクラスの束のせいで、思っていたよりもはるかに困難であることが判明したことがありますか。それはあなたがキーボードを抜くときに、コンピューターの裏で怖いほどもつれたケーブルを見つけ、ひとつだけを選び出す望みがほとんど無いのに似ています。

---

So, here’s some general guidelines to help you keep code untangled and tidy.

----

>だから、これはコードがきちんと解決された状態を保つためのガイドラインです。

---


## Single Responsibility


A given class should be, ideally, responsible for just one task.

----

>指定された(与えられた)クラスは、理想的にはたったひとつのタスクを担当する必要があります。

---


The idea behind Single Responsibility is that each class does its own little task, and then you can solve larger goals by combining these little tasks together. If that sounds like I’m describing components, that’s because the two work perfectly together.

- combine 結合する
- describe 述べる、記述する

----

>SRP(Single Responsibility)の背後にある考え方は、各クラスが独自の小さなタスクを実行し、終了後に一緒にこれらのタスクを組み合わせることで、より大きな目標を解決することができるということです。
もし私がコンポーネントについて述べているように聞こえるならば、それは２つが完全に一緒に動作しているためです。

---

Unity being designed around separation of functionality into reusable parts, Single Responsibility is perhaps the most important principle of the ones I’m going to present in this post.

- design 設計する
- separation 分離

----

>Unityが再利用可能な部品への機能の分離を中心に設計され、SRPは、おそらく私がこの記事で説明するなかで最も重要な原則です。

---

To give an example of this principle, let’s say we have a Player class. Player handles input, physics, weapons, health, and inventory.

- principle 原理、原則
- handle 処理する

----

>この原則の例を与える（行う）ため、プレイヤークラスを持っているとしましょう。
プレイヤーはinput、physics、weapons、health、inventoryを処理します。

---


That’s a rather long list of things the Player is responsible for. We should break this into multiple different components that each do just one thing.

- rather むしろ
- break 分ける

----

>それはプレイヤーが担当するよりもむしろかなり長いリストです。
それらがただ一つのことを行う複数の異なるコンポーネントにこれを分ける必要があります。

---


- PlayerInput – responsible for handling input(入力処理を返す)

- PlayerPhysics – responsible for driving physics simulation(物理演算処理を返す)

- WeaponManager – responsible for managing player weapons(プレイヤーウェポンを管理する)

- Health – responsible for player health(プレイヤーHPを返す)

- PlayerInventory – responsible for player inventory(プレイヤーイベントリーを返す)

---

Ah, much better. Now, these classes are all largely dependent on each other, and that still poses some issues. Let’s take a look at resolving this.

- pose もたらす、引き起こす
- resolve 解決する

----

>ああ、とても良いですね。
さて、これらのクラスは、全てお互いに大きく依存して(従属関係になって)おり、まだ幾つかの問題を引き起こしています。それではその解決を見てみましょう。

---


## Dependency Inversion
>## (依存関係逆転の原則（DIP）

---


If a class relies on another class, abstract that reliance.

----

>もしクラスが他のクラスに依存、抽象的に依存している場合

---


The idea behind Dependency Inversion is that whenever one class calls into another class, we should replace that call with some kind of abstraction to better insulate the classes from each other.


- insulate 絶縁する・隔離する

----

>依存関係逆転の背後にある考え方は、あるクラスが別のクラスに呼ばれるたび、私たちはよりお互いからクラスをより良く切り離し、いくつかの抽象化の種類とその呼出しに置き換えるべきということです。

---

Most preferable is to replace the class dependence with an interface. So class A instead of calling methods in class B, actually calls methods of ISomeInterface which class B implements.

- preferable 好ましい
- instead of ~の代わりに
- 実際に

----

>最も好ましいのは、インターフェイスを持つクラスの依存を置き換えることです。
クラスAに代わって呼び出されるクラスB内のメソッドは、実際にはクラスB実装のISomeInterfaceのメソッドを呼び出します。

---

Another way is to introduce an abstract base class which class B inherits from. So class A treats class B as the base class instead of directly relying on class B itself.

- introduce 導入する

----

>もう一つの方法は、クラスBから継承する抽象基本クラスを導入することです。直接クラスB自体に依存する基底クラスに代わるものとして、クラスBをクラスAとして扱う。

---

The least preferable reliance, of course, is to have class A directly relying on class B. This is the one we want to avoid.

----

>少なくとも好適な依存は、もちろん、クラスAが直接クラスBに依存することです。これは避けたいものです。

---

So in our previous example, those components may have a fairly tight coupling with each other. PlayerInput may rely on the presence of PlayerPhysics, WeaponManager may rely on the presence of Inventory, and so on.

----

>前の例では、これらのコンポーネントは互いにかなりに密結合をしていたと思います。
PlayerInputはPlayerPhysics、WeaponManagerの存在に依存しても良いと。

---

Let’s abstract these.

----

>これらを抽象化してみましょう。

---

- IActorPhysics – Interface for classes which can accept input and presumably affect physics simulation
(入力を受け入れ、おそらく物理演算に影響の与えるインターフェイス)

- IDamageable – Interface for classes which can accept damage
(ダメージを受け入れるインターフェイス)

- IInventory – Interface for classes which can store and retrieve items
(アイテムを保持し回収刷ることが出来るクラスのインターフェイス

---

Now our PlayerPhysics implements IActorPhysics, our Health implements IDamageable, and our PlayerInventory implements IInventory.

----

>現在私たちのPlayerPhysicsはIActorPhysicsを実装し、HealthがIDamageableを実装し、PlayerInventoryがIInventoryを実装しています。

---

So then PlayerInput just relies on the presence of some IActorPhysics, WeaponManager relies on the presence of some IInventory, and perhaps something which deals damage to our player relies on the presence of some IDamageable.

----

>これではPlayerInputはいくつかのIActorPhysicsの存在に依存し、WeaponManagerはIInventoryの存在に依存し、おそらくプレーヤーにダメージを与えるIDamageableの存在に依存している。

---

Dependency Inversion helps reinforce Single Responsibility to some extent. PlayerInput shouldn’t care how the player moves, nor should it care what is going to move the player. Just that there’s something which promises that functionality.

----

>DIPはある程度のSRPをを強化するのに役立ちます。
PlayerInputはプレイヤーがどのように移動するかについて気にしてはならず、しかし、プレイヤーを移動させるために何が起こっているかを気にする必要があります。
ただ、機能性を約束するのです。

---

Another thing to keep in mind is that SendMessage can accomplish the same goals in some cases.

----

>もう一つ心に留めておくべきことは、SendMassage関数はいくつかのケースで同じ目標を達成することができるということです。

---

## Modularization

>モジュール化

---

I’ve personally seen code like this a lot in Unity:


```
switch( behavior )
{
    case 1: // some behavior
    case 2: // another behavior
    case 3: // yet another behavior
    case 4: // the last behavior
}
```

----

>個人的にUnityでよくこのようなコードを見たことがあります。


```
switch( behavior )
{
    case 1: // some behavior
    case 2: // another behavior
    case 3: // yet another behavior
    case 4: // the last behavior
}
```

---

Sure it works, but we can do better. This code is practically screaming to be modularized. Each of those behaviors would be a module, and then “behavior” goes from being an enum or what have you to just being an instance of a module (lets say our module in this case is a delegate, although it could just as easily be a class or struct). So then that code just becomes:


```
behavior();
```


----

> もちろん動作はしますが、しかしより良くすることが可能です。このコードは、実質的にモジュール化されることを望んで(叫んで)います。これらの行動を各モジュールにし、その後、"行動"は列挙型、または何か持っているものをモジュールのインスタンスにする(同じように簡単にすることは出来るが、この場合にはモジュールがdelegateであるが、クラスか構造体にするのが早い)にする。

```
behavior();
```

---

And somewhere else you can assign the current module like:

```
MyClass.behavior = someBehavior;
```

----

> そして、どこか別の場所に、次のように現在のモジュールを割り当てれます。

```
MyClass.behavior = someBehavior;
```

---

Where presumably someBehavior is a function (or, if our module is a class, an instance of that class, or whatever)

----

> おそらく、someBehaviorが関数のとき(またはモジュールがクラスの時、そのクラスのインスタンス、または任意の場合)

---

This is particularly useful if we’re making something like a state machine or a menu system. While we could have a big enum of all of the possible states, or of all of the possible menus, etc it makes a lot of sense to have state and menu be modules we can swap in and out. That way, we don’t have to keep adding new entries to the enum, and we don’t have to keep expanding our switch case statement every time we want to add something.

----

> ステートマシン、またはメニューシステムの・ようなものを作っているとき、これは特に便利です。可能な状態の、もしくは、可能な限りの全てのメニューの、全ての大きな列挙型を持つことが出来ますが、状態とメニューは内と外にスワップ可能なモジュールに出来るという意味になります。そうすれば、列挙型に新しいエントリを追加し続ける必要はなく、switchのケースステートメントは私たちが何かを追加する度に拡大し続ける必要はありません。

---

## Conclusion
> 結論


---

These are not by any means the only coding practices available. But, they are some very important ones to follow.

----

>これらは、任意のコーディング手法では使えません。しかし、これに従うことは非常に重要です。

---

You don’t always have to follow them – sometimes, it’s just overkill and doesn’t make sense. But, do exercise critical thinking and determine whether your code could benefit from them (chances are, it can). Remember, it’s usually not about saving yourself a few lines of code now – it’s about saving yourself a headache later.

- save one'sself ~から身を守る

----

>あなたはいつもこれに従う必要はありませんが、ときにやり過ぎてしまうと意味がありません。しかし、批判的思考(クリティカルシンキング)を行使し、あなたのコードがそれらから利益を得ることが出来るか判別しましょう。(多分できる)　普段はコードのいくつかから自分自身を楽にすることは目的ではありませんが、それはあなた自身を頭痛から防ぎますと覚えて起きましょう。
