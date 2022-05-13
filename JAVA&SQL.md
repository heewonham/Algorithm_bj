# JAVA

```java
Arrays.sort(tickets, new Comparator<String[]>(){
    @Override
    public int compare(String[] o1, String[] o2){
        if(o1[0].toString().contentEquals(o2[0].toString())){
            return o1[1].toString().compareTo(o2[1].toString());
        }else{
            return o1[0].toString().compareTo(o2[0].toString());
        }
    }
});
```

#### Integer[] --> int[]

```java
int[] b = Arrays.stream(a).mapToInt(i -> i).toArray();
```

#### int[] --> Integer[]

```java
Integer[] b = Arrays.stream(a).boxed().toArray(Integer[]::new);
```

#### List -> String[]

```java
String[] sArrays = mList.toArray(new String[mList.size()]);
```

#### String[] -> List

```java
ArrayList mNewList = new ArrayList(Arrays.asList(sArrays));
```



# SQL

LIKE

REGEXP - 정규표현식을 이용해 검색한다. 기본 연산자보다 더 복잡한 문자열 조건을 걸어 데이터를 검색할 수 있다.

`.` : 문자 하나 

* ex ) `...` 은 문자 길이가 세 글자 이상인 것을 찾는다.

`|` : OR이라는 뜻

`[]` : [] 안에 나열된 패턴에 해당하는 문자열을 찾음

* ex ) `[123]d` 은 1d, 2d, 3d를 찾음

`^` : 시작하는 문자열을 찾음 

`$` : 끝나는 문자열을 찾음

`*` : 0회 이상 나타나는 문자  

* `a*` : a 가 0번 이상 등장하는 문자열을 찾음 b , a, aa 모두 해당

`+` : 1회 이상 나타나는 문자

* `a+` : a 가 1번 이상 등장하는 문자열을 찾음 ab, ba, a, 등

`{m,n}` : m회 이상 n회 이하 반복되는 문자

* `치{1,2}` : 치가 1회이상 2회이하 반복된 문자 , 치커리, 치카치카 등

`?` : 0~1회 나타나는 문자

* `[가나다]?` : 가, 나, 다 가 0~1회 등장하는 문자열 찾음. 예를 들어, 가지마, 나라 그리고 안녕도 포함

`[A-z]` 또는 `[:alpha:]` : 알파벳 대문자 혹은 소문자인 문자열을 찾음

* `[A-z]+` : 알파벳이 한개 이상인 문자열 찾음

`[0-9]` 또는 `[:digit:]` : 숫자인 문자열 찾음

* `^[0-9]+` : 한 개 이상의 숫자로 시작하는 문자열을 찾음

`[^문자]` : 문자가 포함하지 않은 문자열을 찾는다



```mysql
# '길' 또는 '로" 또는 '그'가 포함된 문자열을 찾고 싶을 때

# 정규표현식을 사용하지 않을 때
SELECT *
FROM tbl
WHERE data like '%길%'
OR data like '%로%'
OR data like '%그%'

# 정규표현식을 사용할 때
SELECT *
FROM tbl
WHERE data REGEXP '길|로|그'


# ‘안녕’ 또는 ‘하이’로 시작하는 문자열을 찾고 싶을 때

# 정규표현식을 사용하지 않을 때 
SELECT *
FROM tbl  
WHERE data LIKE '안녕%' OR data LIKE '하이%';

# 정규표현식을 사용할 때 
SELECT *
FROM tbl
WHERE data REGEXP ('^안녕|^하이');

-----------------------------------------------

# 길이 7글자인 문자열 중 2번째 자리부터 abc를 포함하는 문자열을 찾고 싶을 때

# 정규표현식을 사용하지 않을 때
SELECT *
FROM tbl
WHERE CHAR_LENGTH(data) = 7 AND SUBSTRING(data, 2, 3) = 'abc';

# 정규표현식을 사용할 때
SELECT *
FROM tbl
WHERE data REGEXP ('^.abc...$');

-----------------------------------------------

# 텍스트와 숫자가 섞여 있는 문자열에서 숫자로만 이루어진 문자열을 찾고 싶을 때

# 정규표현식을 사용하지 않을 때
SELECT *
FROM tbl
WHERE data LIKE ??????????

# 정규표현식을 사용할 때
SELECT *
FROM tbl
WHERE data REGEXP ('^[0-9]+$'); 
-- OR data REGEXP ('^\d$') 
-- OR data REGEXP ('^[:digit:]$');
```



### 조건문

```mysql
# if (조건문, 참, 거짓)
select A.seq, if(A.seq <= 3, 'A', 'B') as result
from Table A
```

```mysql
# case
# 	when 조건1 then '반환값'
# 	when 조건2 then '반환값'
# 	else '반환값'
# end

select
	seq,
	case
		when(u.seq between 1 and 3) then 'A'
		when(u.seq between 4 and 6) then 'B'
		else 'C'
	end as result
from Table u
```

```mysql
# ifnull(null이 아닐 경우 반환값, null일 경우 반환값)
select 
	ifnull(seq,0)
from table
```



#### Order

```mysql
ORDER BY a.DATETIME limit 3 
# 순서대로 정렬하고 3명까지만 출력
```



#### recursive

```mysql
with recursive time as
(
    select 0 hour
    union all
    select hour+1 from time where hour < 23
)

select a.hour HOUR, ifnull(b.cnt,0) COUNT
from time a
    LEFT OUTER JOIN
    (
        SELECT hour, count(hour) cnt
        FROM (SELECT HOUR(DATETIME) hour FROM ANIMAL_OUTS) h 
        GROUP BY hour
    ) b ON a.hour = b.hour
```



#### 가상테이블

```mysql
with temp_table as
(
    select
    from
    ....
)

select * from temp_table
where ...
```

