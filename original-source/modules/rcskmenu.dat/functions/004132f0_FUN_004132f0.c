/*
 * FUN_004132f0 at 004132f0
 * int __register FUN_004132f0(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 004132f0-0041335a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004132f0(int param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  int local_c;
  char local_8 [2];
  short local_6;
  
  uVar2 = FUN_004140d0(param_1,param_2,param_3);
  cVar1 = (char)uVar2;
  if (cVar1 == '\x02') {
    FUN_0041292c(param_1,(undefined4 *)local_8,1);
    local_c = (int)local_8[0];
  }
  else if (cVar1 == '\x03') {
    FUN_0041292c(param_1,(undefined4 *)&local_6,2);
    local_c = (int)local_6;
  }
  else if (cVar1 == '\x04') {
    FUN_0041292c(param_1,&local_c,4);
  }
  else {
    FUN_004124c0();
  }
  return local_c;
}

