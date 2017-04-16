#ifndef TP2_APP_ID_H
#define TP2_APP_ID_H

class IdPaquete {
 private:
  unsigned int src;
  unsigned int dst;
  unsigned short id;
 public:
  IdPaquete();
  IdPaquete(unsigned int src, unsigned int dst, unsigned short id);
  bool operator==(const IdPaquete &p) const;
  ~IdPaquete();
};

#endif //TP2_APP_ID_H
