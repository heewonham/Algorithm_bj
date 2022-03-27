# Algorithm_bj
🔥 백준 알고리즘 문제풀이



테스트 케이스 만드는 방법 :

 `preopen("res/B3055.in","r",stdin);`

`B3055.in`

## # 3425 고스택

1. 입력 처리하는 부분
   명령어 문자 - 명령어에 따라 분기
   NUM 뒤에 숫자가 들어옴
   cpp같은 경우 문자열로 읽게 되면 숫자도 더 읽어야함.
   분기해서 적절한 명령어를 수행해야함
  2. 스택 구현

    직접 구현 혹은 자료구조 사용 
    cpp vector , array - 가장 끝에서 값을 추가 , 제거 등등 
    
    3. 명령어를 구현하는 부분 ... 총 10개 정도 
    
    뭔가 pop할때 없거나 나누기 할때 0이거나 
    값이 너무 크거나 10^9 
    변수 타입은 long으로 써야함. 그리고 예외사항 찾아보기 
    
    4. 초기화 
    5. 어려운 점 : 
       1. 예외처리
       2. 초기화 안되는 것
       3. 디버깅 



### # 2842 집배원 한상덕

* 우체국은 하나밖에 없다.
* 상덕이는 수평, 수직, 대각선 이동가능
* 가장 작은 고도와 가장 높은 고도의 사이 피로도 가장 낮은??



<< 포인트 >>

고도를 가장 낮은 순에서 높은 순으로 정렬한다.

고도를 하나씩 높여가면서 모두 갈 수 있는 높은 고도를 찾는다.

그 고도를 찾으면 낮은 고도를 하나씩 높이고 찾아간다.

--- > 결론 방식은 two pointer 방식임



### # 7453 합이 0인 네 정수

* A[a], B[b], C[c], D[d]의 합이 0인 a, b, c, d 번째의 쌍의 개수를 구하는 것
* 배열의 크기는 4000까지 이므로 총 개수는 4000 * 4 = 16000
* 또한 배열 안의 정수값의 절대값은 2^-28 ~ 2^28 = 268,435,456
* 그러므로 long으로 처리하자 (혹시모르니)



<< 포인트 >>

우선 a,b와 c,d의 합으로 나누고, 정렬한다.

그리고 투포인터 방식으로 a,b의 마이너스와 cd의 값을 비교하여 

cd가 더 크면 , cd을 줄이고 , cd와 ab가 같으면 count를 올려주고, 

ab가 더 크면 ab를 줄이고 합의 개수를 구한다.

 

### # 11050 ~ 11051 이항계수 1, 2

* 일일히 수열과 팩토리얼로 계산
* DP를 활용하여 처리



### # 1010 다리놓기

* N, M개의 사이트가 있음. M은 N가 같거나 크다.
* 다리끼리는 서로 겹쳐질 수 없음
* 경우의 수 구하기



<포인트>

* 이항계수 2와 완전 동일
* DP로 해결한다.



### # 3020 개똥벌레 (range update pointer query)

<포인트>

높이를 기준으로 구간마다 + - 1 처리를 한다.

예를들면, 종유석의 경우는 hit[1] += 1, hit[입력높이+1] -= 1 하고

석순은 hit[총높이 - 입력높이 + 1] += 1 처리를 한다.

후에 for문으로 그동안 계산한 값을 더하면서 최소값과 구간의 수를 구한다.



## 세그먼트 트리와 인덱스트리의 구분

세그먼트 트리 - lazy propagation 

인덱스 트리 - 완전트리? 느낌 



## 세그먼트 트리

> 찾기

``` c++
// 찾기
int seg(int node, int s, int e, int l, int r){
    // 범위를 벗어난 경우
	if( r  < s  || e < l) return ;

	// 범위 이내인 경우
    if( l <= s && e <= r) return node;
	// 범위를 살짝 초과한 경우 - 다시 질문가능
	else{
		return seg(node * 2, s, (s+e) / 2 , l , r) + seg(node * 2 + 1 , (s+e ) / 2 +1, e, l , r);
    }
}
```

> update

```
// update
void update(int node, int s, int e, int idx, int val){
	if(idx < s || e < idx ) return ;
	
	if (s == e ) tr[node] = val;
	else{
		update(node * 2, s, (s+e)/2, idx, val);
		update(node * 2 + 1 , (s+e)/2 + 1, e, idx, val);
		tr[node] = tr[node * 2] + tr[node*2 + 1];
		}
}
```





## 인덱스 트리

> update

``` c++
// update
void update(int num, int val){
	num += PIV
	tree[num] = val;
	n /= 2;

	while(n){
		tree[n] = tree[n*2] + tree[n*2+1];
		n /= 2;
	}
}
```



> query

``` c++
int query(int l, int r){

    l += PIV; r += PIV;
    int ret = 0;

	while(l <= r){

		(l%2 == 1) ret += tree[l++];
        (r%2 == 0) ret += tree[r--];
        l /=2, r /= 2;	
    }

	return ret;
}
```





## # 1572 중앙값

* 세그먼트 트리 문제를 풀 때, 어느 것을 리프노드의 범위로 정할 것인지가 중요하다.
* 중앙값의 경우는 순위를 구하는 것처럼(사탕문제) 5개 중 중앙값은 3번째이기 때문에 리프노드를 총 입력 수인 N이 아니라 범위인 0~65536으로 처리했다.
* 또한 순서대로의 k번째 수열에서 중앙값을 정하는 것이기 때문에 k값이 차면 중앙값을 넣고 처음 넣었던 값을 빼고.. 이런 식으로 합을 더했다.
* 중요한 것은 입력 범위를 꼭 확인할 것!! 0이 포함되는 것을 확인하지 못해서 헤맸음



## # 2449 전구 - DP

* dp 문제는 전 범위의 가장 적은 변경 수를 저장하고 그 수를 점점 갱신한다.
* s ~ i 번째 범위 + (i+1) ~ e의 범위 그리고 s와 e의 색이 다르면 +1 
* 여기서 어디와 어디의 색을 비교할 것인가의 문제가 남는다.
* 동일하게 정한다.
  * 즉, s이면 i+1 왼쪽으로 맞추고
  * e이면 i로 맞춘다. 



## # 1520 내리막길 - DFS + DP

* 갈 수 있는 모든 길 탐색하는 문제이다.
* 갔던 곳 또 들렸다가 갈 수 있음. 즉, 경로만 완전 같지 않으면 한 개의 경로로 인정이된다. 
* 모든 범위를 탐색하는 것이기 때문에 BFS 보다 DFS로 풀어야 함. 목적지에 도달하면 DP +1로 기록한다.
* 그러면 **한번 갔던 곳**은 **기록했던 DP 배열**의 값을 반환하여 한번더 처리하지 않아도 된다. 



## # 3109 빵집 - DFS + 그리디 + DP

* 가장 왼쪽 열에서 오른쪽 열까지 연결되는 파이브의 최대 개수를 구한다. 
* 갈 수 있는 방법은 오른쪽 위 대각선, 오른쪽, 오른쪽 아래 대각선이다.

> 그리디 용법

* 결국, 위에서 그 길을 사용하면 밑에서는 그 길을 사용할 수 없고, 최대 개수를 구하기 위해서는 **결국 각 루트당 가장 위쪽을 이용해서 갈 수 있는 길을 찾아야 한다.** (그리디적 용법)
*  도달할 수 있음을 확인한 가장 왼쪽 열은 다른 방법을 굳이 찾을 필요가 없으므로 return을 통해 DFS를 종료한다.
* *그런데*

> DP 적 요소

* 자꾸 **시간초과**가 발생했다. 원인을 찾기위해 ios::sync_with_stdio(false); 추가 등의 처리 했지만 여전히 시간초과였다.
* 그 이유는 **오른쪽 열에 도달한 경우에만 지점의 visited를 true로 바뀐 까닭이었다.**
  * 어차피, 그 지점을 방문해서 오른쪽 열까지 도달하지 못한다면 또다시 그 지점을 방문했을 때도 길을 찾지 못하기 때문에 (DP적으로)
  * 위에서 **한번 방문한 곳 (도달하지 않더라도) true**로 바꾸면 밑에서 경로를 찾을 때 똑같은 지점을 다시 방문하지 않아도 됨으로 시간초과에서 벗어날 수 있었다.  



## # 입국심사(프로그래머스) - 이분탐색

* **long long** 범위 : -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19자리)
* **unsigned long long** 범위 : 0 to 18,446,744,073,709,551,615(20자리)



* n : 1 ~ 1,000,000,000명 이하
* time :  1 ~ 1,000,000,000명 이하
* 심사관 수: 1 ~ 100,000



첫번째 해결 방안 : 

* 세그먼트 트리를 이용해서 심사관 중 가장 빨리 끝낸 사람을 찾고 그 심사관 갱신한다. 이런 방식으로 모든 고객을 처리하여 시간을 구한다.
* 이 경우의 시간 복잡도는 
  * 최악의 경우 : 1,000,000,000(n) * 100,000(심사관) = 100,000,000,000,000 (15자리 long 이내)
  * 그러나 세그먼트 특성상 100,000의 경우는 17번이내 찾을 수 있으므로
  *  1,000,000,000 * 17 = 17,000,000,000 번의 연산을 수행(+기타 연산 작업이 수행된다) 
* 그러나 6,7,8 의 문제에서 **시간초과**가 발생하게 된다. 



두번째 해결 방안:

* 최소의 시간에서 최악의 시간을 구하고, 그 시간을 반씩 줄여가면서 해당 시간 내에 심사관이 최대 몇 명이 고객을 처리할 수 있는지를 찾아가는 방법
* 이 경우의 시간 복잡도는 
  * 1,000,000,000명의 사람이 1,000,000,000 시간을 소요하는 심사관에서 처리할 경우
  * 1,000,000,000,000,000,000 (19자리) -> long long 범위 내임
  * log(1,000,000,000,000,000,000)일 경우 대략 50번 작동
  * 그러나 해당 시간 내 심사관이 최대 몇명을 처리하는 지의 연산과정이 필요함으로 100,000(심사관수) * 50번 연산을 수행
  * 그러면 5,000,000 번의 연산을 수행한다.



## # 순위(프로그래머스) - 그래프

* 선수의 수 1 ~100
* 경기 결과 1 ~ 4500
* 모든 경기 결과의 **모순**은 존재하지 않는다.



* 결국, 내가 패배했던 x를 이긴 수y는 결국 나를 이긴 것이다.
* 그러므로 모든 x을 하나씩 순회하면서 x을 이길 수 있는 노드의 수와 x에게 지는 노드의 수를 구한다.
* 이긴 노드와 진 노드의 개수가 n-1개일 경우 정보를 취합하면 순위를 구할 수 있으므로 정답을 하나씩 더하면 결과를 구할 수 있다. 

 

## # 숨바꼭질 4 - BFS

* 이 문제의 포인트는 BFS로 구한 최단 거리의 path를 어떻게 출력하는지의 초점이 있었다,
* 해결책은 처음 visited가 true가 된 시점은 그 지점에 먼저 갈 수 있는 루트임으로 이동할 때 parent의 노드로 기록해두면 나중에 역추적하기 쉽다.



## # 1450 knapsack 문제 - 이분탐색, 경우의 수

1. n / 2 로 나눈다 
2. 각 배열 조합 구하기 (가능한 무게)
3. 두 배열로 경우의수 구하기 (upper bound 활용)



> 예 : 
>
> 6 6
>
> 1 2 3 1 2 3 
>
> 왼쪽 배열(1, 2, 3)의 가능한 무게는 0, 1, 2, 3, 3, 4, 5, 6 이고 가능한 조합은 8개이다.
>
> 오른쪽 배열(1, 2 ,3) 역시 왼쪽 배열과 똑같다.
>
> 
>
> 그 다음, 
>
> 왼쪽 배열을 기준으로 오른쪽 배열의 수 중 6이라는 범위내에 합칠 수 있는 개수를 센다.
>
> 왼쪽 배열의 0의 경우는 오른쪽 배열에서 합칠 수 있는 수는 모두 가능하기 때문에 : 8개
>
> 왼쪽 배열의 1의 경우는 오른쪽 배열에서 합칠 수 있는 수 : 7 개
>
> :
>
> :
>
> 왼쪽 배열의 5의 경우 오른쪽 배열에서 합칠 수 있는 수 : 2 개(0, 1)
>
> 왼쪽 배열의 6의 경우 오른쪽 배열에서 합칠 수 있는 수 : 1개 (0)
>
> 
>
> 그러므로
>
> 즉, 0 -> 8개, 1 -> 7개, 2 -> 6개, 3 -> 5개, 3-> 5개, 4 -> 3개, 5 -> 2개, 6 - > 1개
>
> 를 합친 개수는 37로 경우의 수는 37이다. 



### java로 lowerbound, upperbound 구하기

#### lowerbound

* 범위 안의 원소들 중 특정 target보다 **크거나 같은 첫번째의 원소의 인덱스**

``` java
private static int lowerBound(List<Integer> data, int target) {
    int begin = 0;
    int end = data.size();
    
    while(begin < end) {
    	int mid = (begin + end) / 2;
        
        if(data.get(mid) >= target) {
        	end = mid;
        }
        else {
        	begin = mid + 1;
        }
    }
    return end;
}
```



#### upper_bound

* 범위 안의 원소들 중 특정 **target보다 큰** 첫번째 원소의 인덱스

```java
private static int upperBound(List<Integer> data, int target) {
    int begin = 0;
    int end = data.size();
    
    while(begin < end) {
    	int mid = (begin + end) / 2;
        
        if(data.get(mid) <= target) {
        	begin = mid + 1;
        }
        else {
        	end = mid;
        }
    }
    return end;
}
```



## 14503 로봇청소기 (dfs + 조건문 잘 읽기)

1. 현재 위치를 청소한다.
2. 현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 차례대로 인접한 칸을 탐색한다.
   1. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 `1번부터 진행`한다.
   2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
   3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 `후진을 하고 2번`으로 돌아간다.
   4. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.



전제는 보통의 dfs처럼 청소할 공간이 없으면 위치로 돌아가는 것이 아니라 **후진**을 하는 것이다. 단, 후진은 청소를 했든 안했든 상관없이 벽만 아니면 가능하다.

그리고 청소를 하는 경우는 맨 처음 출발하는 경우와 `2-1인 경우`에만 가능하다는 걸 주의해야한다. 즉, 후진을 할 때, 청소가 되어있지 않아도 청소를 하지 않고 `왼쪽방향부터 탐색`해 들어가야 한다. 



### 프로그래머스 - 신규아이디 추천(정규표현식)

이 문제는 정규 표현식을 알지 못하면 복잡하게 풀어야하는 그런 문제이다.

`^` : 문자열의 시작

`$` : 문자열의 종료

`.` : 임의의 한 문자

`[]` 문자 클래스 : 문자클래스에 들어간 문자는 하나의 문자로 취급된다.

* 문자 클래스에서 `^` not을 의미한다.
* 문자 클래스에서 `-` 즉, a-z는 a에서 z까지의 문자를 말한다.

`[^-_.a-z0-9]` : `-`, `_` , `.`, a에서 z, 0에서 9 가 `아니면` 이라는 뜻이다.



- `?`: 앞 문자가 없거나 하나 있음
- `+`: 앞 문자가 1개 이상임
- `*`: 앞 문자가 0개 이상임

- `{n,m`}: 앞 문자가 `n`개 이상 `m`개 이하. `{0,1`}은 `?`와 같은 의미다.
- `{n,`}: 앞 문자가 `n`개 이상. 위의 형태에서 `m`이 생략된 형태이다. `{0,`}이면 `*`와 같고 `{1,`}이면 `+`와 같은 의미이다.
- `{n`}: 앞 문자가 정확히 `n`개. `{n,n`}과 같은 의미이다.

예를 들어,

`[.]{2,}` : `.`이라는 문자 클래스가 2개 이상 것

`^[.]|[.$]` : 시작이 `.`이거나 끝이 `.`인 경우 



#### 내가 풀었던 방식

```java
class Solution {
    public String solution(String new_id) {
        String answer = "";

        answer = new_id.toLowerCase(); // 1case
        answer = twoCase(answer); // 2case
        answer = threeCase(answer); // 3case
        answer = firstCheck(answer); // 4case : 첫번째문자열  
        answer = lastCheck(answer); // 4case : 마지막문자열
           
        // 5. 아이디가 빈 문자열이면 a 대입
        if(answer.length() == 0){
            answer = "a";
        }
        
        // 6. 16자이상이라면 15자까지 저장
        if(answer.length() >= 16){
            answer = answer.substring(0,15);
        }
        answer = lastCheck(answer); // 마지막 문자열
        
        // 7. 두글자 이하면 마지막 글자를 길이 3이될때까지 추가
        if(answer.length() <= 2){
            char last = answer.charAt(answer.length()-1);
            for(int i = answer.length(); i < 3; i++){
                answer += Character.toString(last);
            }
        }
        return answer;
    }
    
    boolean checkOk(char ch){
        if(ch-'0' >= 49 && ch-'0' <= 74){
            return true;
        } else if(ch-'0' >= 0 && ch-'0' <= 9 ){
            return true;
        } else if(ch == '-') {
            return true;
        } else if(ch == '_'){
            return true;
        } else if(ch == '.'){
            return true;
        } else{
            return false;
        }
    }
    
    String twoCase(String str){
        // 2. 소문자, 숫자, 빼기, 밑줄, 마침표 제외 모두 제거
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < str.length(); i++){
            char ch = str.charAt(i);
            if(checkOk(ch)){
                sb.append(Character.toString(ch));
            }
        }
        return sb.toString();   
    }
    String threeCase(String str){
        // 3. 마침표 2번 이상 -> 하나로
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < str.length(); i++){
            char ch = str.charAt(i);
            if(ch == '.'){
                int j = i;
                for(; j < str.length(); j++){
                    if(str.charAt(j) != '.') break;
                }
                sb.append(".");
                i = j-1;
            } else{
                sb.append(Character.toString(ch));
            }
        }
        return sb.toString();   
    }
    String firstCheck(String str){
        int len = str.length();
        if(len > 0 && str.charAt(0) == '.'){
            str = str.substring(1);
        }
        return str;
    }
    
    String lastCheck(String str){
        int len = str.length();
        if(len > 0 && str.charAt(len-1) == '.'){
            str = str.substring(0,len-1);
        }
        return str;
    }
}
```



#### 정규표현식으로 표현된 방식

```java
class Solution {
    public String solution(String new_id) {
        String answer = "";
        String temp = new_id.toLowerCase();

        temp = temp.replaceAll("[^-_.a-z0-9]","");
        System.out.println(temp);
        temp = temp.replaceAll("[.]{2,}",".");
        temp = temp.replaceAll("^[.]|[.]$","");
        System.out.println(temp.length());
        if(temp.equals(""))
            temp+="a";
        if(temp.length() >=16){
            temp = temp.substring(0,15);
            temp=temp.replaceAll("^[.]|[.]$","");
        }
        if(temp.length()<=2)
            while(temp.length()<3)
                temp+=temp.charAt(temp.length()-1);

        answer=temp;
        return answer;
    }
}
```

엄청난 길이의 차이를 볼 수 있다.



### 프로그래머스 - H-Index **

어떤 과학자가 발표한 n편 중 h번 이상 인용된 논문이 h편 이상이고, 나머지가 h이하로 인용된 경우 과학자의 H-Index이다.

* n : 1~1,000
* 논문별 인용 횟수 : 0 ~ 10,000

H-Index의 최대값은 n의 최대값이다.

그러므로 sort를 진행 후 ,  

```java
        for(int i = 0; i < len; i++){
            int cnt = len - i; 
            if(citations[i] >= cnt){
                return cnt;
            }
        }
```



