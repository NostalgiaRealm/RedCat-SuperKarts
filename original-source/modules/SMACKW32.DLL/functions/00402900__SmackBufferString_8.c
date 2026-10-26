/*
 * _SmackBufferString@8 at 00402900
 * char * __stdcall _SmackBufferString@8(char * param_1, ushort param_2)
 * Address ranges: 00402900-00402933
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * _SmackBufferString_8(char *param_1,ushort param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
                    /* 0x2900  1  _SmackBufferString@8 */
  if (4 < param_2) {
    param_2 = 4;
  }
  pcVar2 = (&PTR_s_Automatic_0040e824)[param_2];
  do {
    pcVar3 = param_1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    *pcVar3 = cVar1;
    param_1 = pcVar3 + 1;
  } while (cVar1 != '\0');
  return pcVar3;
}

