/*
 * FUN_00411338 at 00411338
 * undefined FUN_00411338(void)
 * Address ranges: 00411338-0041138c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00411338(int *param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  int iStack_10;
  
  if ((char)param_1[6] == '\0') {
    iStack_10 = param_1[4];
  }
  else {
    iStack_10 = param_3;
    cVar1 = (**(code **)(*param_1 + 0x78))(param_1,param_2,&iStack_10);
    if (cVar1 != '\0') {
      if (*(char *)((int)param_1 + 0x19) == '\0') {
        return iStack_10;
      }
      if (*(char *)((int)param_1 + 0x19) == '\x02') {
        FUN_004108f0(param_1,(undefined4 *)PTR_PTR_0047c6d0,0);
      }
    }
  }
  FUN_00411660(param_1,iStack_10,param_2);
  return iStack_10;
}

