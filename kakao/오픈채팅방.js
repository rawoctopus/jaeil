// 채팅방을 나간 후 새로운 닉네임
// 채팅방에서 닉네임 변경
// Enter userID nickname
// Change userID nickname
// Leave userID


function solution(record) {
    const result = [];
    const map = {};
    const _action = {
        Enter: (id, name) => {
            map[id] = name;
            result.push([id,'enter']);
        },
        Leave: (id) => {
            result.push([id,'leave']);
        },
        Change: (id, name) => {
            map[id] = name;
        }
    };
    const msg = {
        'enter': '들어왔습니다.',
        'leave': '나갔습니다.'
    }
    record.forEach(line => {
        const [cmd, id, nickname] = line.split(' ');
        _action[cmd](id, nickname);
    });
    return result.map(log => {
        return `${map[log[0]]}님이 ${msg[log[1]]}`;
    })    
}
console.log(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]))