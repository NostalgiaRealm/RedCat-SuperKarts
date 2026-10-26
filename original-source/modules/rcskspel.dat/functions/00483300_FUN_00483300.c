/*
 * FUN_00483300 at 00483300
 * undefined FUN_00483300(void)
 * Address ranges: 00483300-0048334d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 __thiscall FUN_00483300(int *param_1,float param_2)

{
  float fVar1;
  char cVar2;
  int iVar3;
  
  if ((char)param_1[0x2a] == '\0') {
    if (param_1[1] == 0) {
      fVar1 = (float)param_1[5];
      param_1[5] = (int)(param_2 + fVar1);
      if ((float)param_1[6] <= param_2 + fVar1) {
        return 0;
      }
      iVar3 = *param_1;
    }
    else {
      iVar3 = *param_1;
      if (param_1[1] == 1) {
        cVar2 = (**(code **)(iVar3 + 4))();
        if (cVar2 != '\0') {
          return 1;
        }
        return 0;
      }
    }
    (**(code **)(iVar3 + 4))(param_2);
  }
  return 1;
}

