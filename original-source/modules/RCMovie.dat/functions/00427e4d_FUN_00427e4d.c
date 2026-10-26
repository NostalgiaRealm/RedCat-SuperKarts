/*
 * FUN_00427e4d at 00427e4d
 * uint * __cdecl FUN_00427e4d(uint * param_1)
 * Address ranges: 00427e4d-00427eea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint * __cdecl FUN_00427e4d(uint *param_1)

{
  char cVar1;
  size_t _Size;
  int iVar2;
  uint *puVar3;
  LPWSTR local_8;
  
  local_8 = (LPWSTR)0x0;
  if (DAT_0043e588 == 0) {
    cVar1 = (char)*param_1;
    puVar3 = param_1;
    while (cVar1 != '\0') {
      cVar1 = (char)*puVar3;
      if (('`' < cVar1) && (cVar1 < '{')) {
        *(char *)puVar3 = cVar1 + -0x20;
      }
      puVar3 = (uint *)((int)puVar3 + 1);
      cVar1 = *(char *)puVar3;
    }
  }
  else {
    _Size = FUN_00426301(DAT_0043e588,0x200,(char *)param_1,-1,(LPWSTR)0x0,0,0,1);
    if (((_Size != 0) && (local_8 = _malloc(_Size), local_8 != (LPWSTR)0x0)) &&
       (iVar2 = FUN_00426301(DAT_0043e588,0x200,(char *)param_1,-1,local_8,_Size,0,1), iVar2 != 0))
    {
      FUN_0041f7a0(param_1,(uint *)local_8);
    }
    FUN_0041fd93(local_8);
  }
  return param_1;
}

