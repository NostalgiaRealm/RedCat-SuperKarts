/*
 * FUN_004734b4 at 004734b4
 * char __register FUN_004734b4(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 004734b4-004734d4;004734e9-0047352d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char FUN_004734b4(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  
  switch(*(undefined1 *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x24)) {
  case 0:
    cVar1 = '\x01';
    break;
  case 1:
    cVar1 = FUN_004732d8();
    break;
  case 2:
    cVar1 = FUN_00473338();
    break;
  case 3:
    cVar1 = FUN_00473428(param_1,param_2,param_3);
    break;
  case 4:
    cVar1 = '\x01';
    break;
  default:
    cVar1 = '\x01';
  }
  if (cVar1 == '\x01') {
    FUN_00473298();
  }
  else {
    FUN_00473204();
  }
  return cVar1;
}

