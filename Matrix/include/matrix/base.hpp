namespace Matrix {
class Matrix {
protected:
  int rows_;

public:
  virtual ~Matrix() {}
  virtual void Display() const = 0;
  virtual int &operator()(int i, int j) = 0;
  virtual int operator()(int i, int j) const = 0;
};
} // namespace Matrix