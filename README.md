get_next_line에서 마지막에 return되는 line은 main에서 할당 해제해야한다.
따라서 remain 함수에서 backup이 null로 return (0)이 되어도 line은 굳이 해제하지 않아도 된다.