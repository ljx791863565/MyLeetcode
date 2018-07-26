import java.util.*;

public class ShowHand
{
	
	private final int PLAY_NUM = 5;
	//牌的花色
	private String []types = {"\4 ", "\5 ", "\3 ", "\6 "};
	//牌的值
	private String []value = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	//牌堆里剩余的牌
	private List<String> cards = new LinkedList<String>();
	//定义玩家
	private String[] players = new String[PLAY_NUM];
	//玩家的手牌
	private	List<String>[] playersCards = new List[PLAY_NUM];

	/**
	  初始化牌，放入52张并且随机打乱排列
	  */
	public void initCards()
	{
		for (int i = 0; i < types.length; i++){
			for (int j = 0; j < value.length; j++){
				cards.add(types[i] + value[j]);
			}
		}
		//随机排列   洗牌
		Collections.shuffle(cards);
	}
	
	/**
	  初始化玩家,开始时每个玩家手牌为0
	  */
	public void initPlayer(String... names)
	{
		if (names.length > PLAY_NUM || names.length < 2){
			System.out.println("玩家的数量不对");
			return;
		}else{
			for (int i = 0; i < names.length; i++){
				//初始化玩家名字
				players[i] = names[i];
			}
		}
	}

	/**
	  初始化玩家手牌
	  */
	public void initPlayerCards()
	{
		for (int i = 0; i < players.length; i++){
			if (players[i] != null && !players[i].equals("")){
				playersCards[i] = new LinkedList<String>();
			}
		}
	}

	/**
	  输出全部的牌
	  */
	public void showAllCards()
	{
		for (String card : cards){
			System.out.println(card);
		}
	}

	/**
	  派牌
	  */
	public void deliverCard(String first)
	{
		int firstPos = ArrayUtils.search(players, first);
		for (int i = firstPos; i < PLAY_NUM; i++){
			if (players[i] != null){
				playersCards[i].add(cards.get(0));
				cards.remove(0);
			}
		}
		for (int i = 0; i < firstPos; i++){
			if (players[i] != null){
				playersCards[i].add(cards.get(0));
				cards.remove(0);
			}
		}
	}

	/**
	  输出玩家的手牌
	  */
	public void showPlayerCards()
	{
		for (int i = 0; i < PLAY_NUM; i++){
			if (players[i] != null){
				System.out.println(players[i] + ": ");
				for (String card : playersCards[i]){
					System.out.print(card + "\t");
				}
			}
			System.out.print("\n");
		}
	}
	
	public static void main(String []args)
	{
		ShowHand sh = new ShowHand();
		sh.initPlayer("电脑玩家", "高进");
		sh.initCards();
		sh.initPlayerCards();
		sh.showAllCards();

		System.out.println("========================");
		sh.deliverCard("高进");
		sh.showPlayerCards();

		sh.deliverCard("电脑玩家");
		sh.showPlayerCards();
	}
}
